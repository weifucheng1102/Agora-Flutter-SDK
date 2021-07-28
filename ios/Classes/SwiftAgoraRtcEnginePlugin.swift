import Flutter
import UIKit

public class SwiftAgoraRtcEnginePlugin: NSObject, FlutterPlugin, FlutterStreamHandler {
    private var registrar: FlutterPluginRegistrar?
    private var methodChannel: FlutterMethodChannel?
    private var eventChannel: FlutterEventChannel?
    private var eventSink: FlutterEventSink?
    private lazy var manager: RtcEngineManager = {
        RtcEngineManager { [weak self] methodName, data in
            self?.emit(methodName, data)
        }
    }()

    private lazy var rtcChannelPlugin: AgoraRtcChannelPlugin = {
        AgoraRtcChannelPlugin(self)
    }()

    public static func register(with registrar: FlutterPluginRegistrar) {
        let rtcEnginePlugin = SwiftAgoraRtcEnginePlugin()
        rtcEnginePlugin.registrar = registrar
        rtcEnginePlugin.rtcChannelPlugin.initPlugin(registrar)
        rtcEnginePlugin.initPlugin(registrar)
    }

    private func initPlugin(_ registrar: FlutterPluginRegistrar) {
        methodChannel = FlutterMethodChannel(name: "agora_rtc_engine", binaryMessenger: registrar.messenger())
        eventChannel = FlutterEventChannel(name: "agora_rtc_engine/events", binaryMessenger: registrar.messenger())
        registrar.addMethodCallDelegate(self, channel: methodChannel!)
        eventChannel?.setStreamHandler(self)

        registrar.register(AgoraSurfaceViewFactory(registrar.messenger(), self, rtcChannelPlugin), withId: "AgoraSurfaceView")
    }

    public func detachFromEngine(for registrar: FlutterPluginRegistrar) {
        rtcChannelPlugin.detachFromEngine(for: registrar)
        methodChannel?.setMethodCallHandler(nil)
        eventChannel?.setStreamHandler(nil)
        manager.Release()
    }

    public func onListen(withArguments _: Any?, eventSink events: @escaping FlutterEventSink) -> FlutterError? {
        eventSink = events
        return nil
    }

    public func onCancel(withArguments _: Any?) -> FlutterError? {
        eventSink = nil
        return nil
    }

    private func emit(_ methodName: String, _ data: [String: Any?]?) {
        var event: [String: Any?] = ["methodName": methodName]
        if let data = data {
            event.merge(data) { current, _ in
                current
            }
        }
        eventSink?(event)
    }

    weak var engine: AgoraRtcEngineKit? {
        return manager.engine
    }

    public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        if call.method == "createTextureRender" {
            let id = AgoraTextureViewFactory.createTextureRender(registrar!.textures(), registrar!.messenger(), self, rtcChannelPlugin)
            result(id)
            return
        } else if call.method == "destroyTextureRender" {
            if let params = call.arguments as? NSDictionary {
                if let id = params["id"] as? NSNumber {
                    AgoraTextureViewFactory.destroyTextureRender(id.int64Value)
                }
            }
            return
        }

        if call.method == "getAssetAbsolutePath" {
            getAssetAbsolutePath(call, result: result)
            return
        }
        if let params = call.arguments as? NSDictionary {
            let selector = NSSelectorFromString(call.method + "::")
            if manager.responds(to: selector) {
                manager.perform(selector, with: params, with: ResultCallback(result))
                return
            }
        } else {
            let selector = NSSelectorFromString(call.method + ":")
            if manager.responds(to: selector) {
                manager.perform(selector, with: ResultCallback(result))
                return
            }
        }
        result(FlutterMethodNotImplemented)
    }

    private func getAssetAbsolutePath(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        if let assetPath = call.arguments as? String {
            if let assetKey = registrar?.lookupKey(forAsset: assetPath) {
                if let realPath = Bundle.main.path(forResource: assetKey, ofType: nil) {
                    result(realPath)
                    return
                }
            }
            result(FlutterError(code: "FileNotFoundException", message: nil, details: nil))
            return
        }
        result(FlutterError(code: "IllegalArgumentException", message: nil, details: nil))
    }
}
