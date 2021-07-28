//
// Created by LXH on 2021/1/14.
//

#ifndef IRIS_RTC_BASE_H_
#define IRIS_RTC_BASE_H_

#include "iris_base.h"
#include <cstdint>
#if defined(__APPLE__)
#include <TargetConditionals.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
enum EngineType {
  kEngineTypeNormal,
  kEngineTypeSubProcess,
};

enum ApiTypeEngine {
  kEngineInitialize,
  kEngineRelease,
  kEngineSetChannelProfile,
  kEngineSetClientRole,
  kEngineJoinChannel,
  kEngineSwitchChannel,
  kEngineLeaveChannel,
  kEngineRenewToken,
  kEngineRegisterLocalUserAccount,
  kEngineJoinChannelWithUserAccount,
  kEngineGetUserInfoByUserAccount,
  kEngineGetUserInfoByUid,
  kEngineStartEchoTest,
  kEngineStopEchoTest,
  kEngineSetCloudProxy,
  kEngineEnableVideo,
  kEngineDisableVideo,
  kEngineSetVideoProfile,
  kEngineSetVideoEncoderConfiguration,
  kEngineSetCameraCapturerConfiguration,
  kEngineSetupLocalVideo,
  kEngineSetupRemoteVideo,
  kEngineStartPreview,
  kEngineSetRemoteUserPriority,
  kEngineStopPreview,
  kEngineEnableAudio,
  kEngineEnableLocalAudio,
  kEngineDisableAudio,
  kEngineSetAudioProfile,
  kEngineMuteLocalAudioStream,
  kEngineMuteAllRemoteAudioStreams,
  kEngineSetDefaultMuteAllRemoteAudioStreams,
  kEngineAdjustUserPlaybackSignalVolume,
  kEngineMuteRemoteAudioStream,
  kEngineMuteLocalVideoStream,
  kEngineEnableLocalVideo,
  kEngineMuteAllRemoteVideoStreams,
  kEngineSetDefaultMuteAllRemoteVideoStreams,
  kEngineMuteRemoteVideoStream,
  kEngineSetRemoteVideoStreamType,
  kEngineSetRemoteDefaultVideoStreamType,
  kEngineEnableAudioVolumeIndication,
  kEngineStartAudioRecording,
  kEngineStopAudioRecording,
  kEngineStartAudioMixing,
  kEngineStopAudioMixing,
  kEnginePauseAudioMixing,
  kEngineResumeAudioMixing,
  kEngineSetHighQualityAudioParameters,
  kEngineAdjustAudioMixingVolume,
  kEngineAdjustAudioMixingPlayoutVolume,
  kEngineGetAudioMixingPlayoutVolume,
  kEngineAdjustAudioMixingPublishVolume,
  kEngineGetAudioMixingPublishVolume,
  kEngineGetAudioMixingDuration,
  kEngineGetAudioMixingCurrentPosition,
  kEngineSetAudioMixingPosition,
  kEngineSetAudioMixingPitch,
  kEngineGetEffectsVolume,
  kEngineSetEffectsVolume,
  kEngineSetVolumeOfEffect,
  kEngineEnableFaceDetection,
  kEnginePlayEffect,
  kEngineStopEffect,
  kEngineStopAllEffects,
  kEnginePreloadEffect,
  kEngineUnloadEffect,
  kEnginePauseEffect,
  kEnginePauseAllEffects,
  kEngineResumeEffect,
  kEngineResumeAllEffects,
  kEngineGetEffectDuration,
  kEngineSetEffectPosition,
  kEngineGetEffectCurrentPosition,
  kEngineEnableDeepLearningDenoise,
  kEngineEnableSoundPositionIndication,
  kEngineSetRemoteVoicePosition,
  kEngineSetLocalVoicePitch,
  kEngineSetLocalVoiceEqualization,
  kEngineSetLocalVoiceReverb,
  kEngineSetLocalVoiceChanger,
  kEngineSetLocalVoiceReverbPreset,
  kEngineSetVoiceBeautifierPreset,
  kEngineSetAudioEffectPreset,
  kEngineSetVoiceConversionPreset,
  kEngineSetAudioEffectParameters,
  kEngineSetVoiceBeautifierParameters,
  kEngineSetLogFile,
  kEngineSetLogFilter,
  kEngineSetLogFileSize,
  kEngineUploadLogFile,
  kEngineSetLocalRenderMode,
  kEngineSetRemoteRenderMode,
  kEngineSetLocalVideoMirrorMode,
  kEngineEnableDualStreamMode,
  kEngineSetExternalAudioSource,
  kEngineSetExternalAudioSink,
  kEngineSetRecordingAudioFrameParameters,
  kEngineSetPlaybackAudioFrameParameters,
  kEngineSetMixedAudioFrameParameters,
  kEngineAdjustRecordingSignalVolume,
  kEngineAdjustPlaybackSignalVolume,
  kEngineAdjustLoopBackRecordingSignalVolume,
  kEngineEnableWebSdkInteroperability,
  kEngineSetVideoQualityParameters,
  kEngineSetLocalPublishFallbackOption,
  kEngineSetRemoteSubscribeFallbackOption,
  kEngineSwitchCamera,
  kEngineSetDefaultAudioRouteToSpeakerPhone,
  kEngineSetEnableSpeakerPhone,
  kEngineEnableInEarMonitoring,
  kEngineSetInEarMonitoringVolume,
  kEngineIsSpeakerPhoneEnabled,
  kEngineSetAudioSessionOperationRestriction,
  kEngineEnableLoopBackRecording,
  kEngineStartScreenCaptureByDisplayId,
  kEngineStartScreenCaptureByScreenRect,
  kEngineStartScreenCaptureByWindowId,
  kEngineSetScreenCaptureContentHint,
  kEngineUpdateScreenCaptureParameters,
  kEngineUpdateScreenCaptureRegion,
  kEngineStopScreenCapture,
  kEngineStartScreenCapture,
  kEngineSetVideoSource,
  kEngineGetCallId,
  kEngineRate,
  kEngineComplain,
  kEngineGetVersion,
  kEngineEnableLastMileTest,
  kEngineDisableLastMileTest,
  kEngineStartLastMileProbeTest,
  kEngineStopLastMileProbeTest,
  kEngineGetErrorDescription,
  kEngineSetEncryptionSecret,
  kEngineSetEncryptionMode,
  kEngineEnableEncryption,
  kEngineRegisterPacketObserver,
  kEngineCreateDataStream,
  kEngineSendStreamMessage,
  kEngineAddPublishStreamUrl,
  kEngineRemovePublishStreamUrl,
  kEngineSetLiveTranscoding,
  kEngineAddVideoWaterMark,
  kEngineClearVideoWaterMarks,
  kEngineSetBeautyEffectOptions,
  kEngineEnableVirtualBackground,
  kEngineAddInjectStreamUrl,
  kEngineStartChannelMediaRelay,
  kEngineUpdateChannelMediaRelay,
  kEnginePauseAllChannelMediaRelay,
  kEngineResumeAllChannelMediaRelay,
  kEngineStopChannelMediaRelay,
  kEngineRemoveInjectStreamUrl,
  kEngineSendCustomReportMessage,
  kEngineGetConnectionState,
  kEngineEnableRemoteSuperResolution,
  kEngineRegisterMediaMetadataObserver,
  kEngineSetParameters,
  kEngineSetLocalAccessPoint,

  kEngineUnRegisterMediaMetadataObserver,
  kEngineSetMaxMetadataSize,
  kEngineSendMetadata,
  kEngineSetAppType,

  kMediaPushAudioFrame,
  kMediaPullAudioFrame,
  kMediaSetExternalVideoSource,
  kMediaPushVideoFrame,
};

enum ApiTypeChannel {
  kChannelCreateChannel,
  kChannelRelease,
  kChannelJoinChannel,
  kChannelJoinChannelWithUserAccount,
  kChannelLeaveChannel,
  kChannelPublish,
  kChannelUnPublish,
  kChannelChannelId,
  kChannelGetCallId,
  kChannelRenewToken,
  kChannelSetEncryptionSecret,
  kChannelSetEncryptionMode,
  kChannelEnableEncryption,
  kChannelRegisterPacketObserver,
  kChannelRegisterMediaMetadataObserver,
  kChannelUnRegisterMediaMetadataObserver,
  kChannelSetMaxMetadataSize,
  kChannelSendMetadata,
  kChannelSetClientRole,
  kChannelSetRemoteUserPriority,
  kChannelSetRemoteVoicePosition,
  kChannelSetRemoteRenderMode,
  kChannelSetDefaultMuteAllRemoteAudioStreams,
  kChannelSetDefaultMuteAllRemoteVideoStreams,
  kChannelMuteLocalAudioStream,
  kChannelMuteLocalVideoStream,
  kChannelMuteAllRemoteAudioStreams,
  kChannelAdjustUserPlaybackSignalVolume,
  kChannelMuteRemoteAudioStream,
  kChannelMuteAllRemoteVideoStreams,
  kChannelMuteRemoteVideoStream,
  kChannelSetRemoteVideoStreamType,
  kChannelSetRemoteDefaultVideoStreamType,
  kChannelCreateDataStream,
  kChannelSendStreamMessage,
  kChannelAddPublishStreamUrl,
  kChannelRemovePublishStreamUrl,
  kChannelSetLiveTranscoding,
  kChannelAddInjectStreamUrl,
  kChannelRemoveInjectStreamUrl,
  kChannelStartChannelMediaRelay,
  kChannelUpdateChannelMediaRelay,
  kChannelPauseAllChannelMediaRelay,
  kChannelResumeAllChannelMediaRelay,
  kChannelStopChannelMediaRelay,
  kChannelGetConnectionState,
  kChannelEnableRemoteSuperResolution,
};

enum ApiTypeAudioDeviceManager {
  kADMEnumeratePlaybackDevices,
  kADMSetPlaybackDevice,
  kADMGetPlaybackDevice,
  kADMGetPlaybackDeviceInfo,
  kADMSetPlaybackDeviceVolume,
  kADMGetPlaybackDeviceVolume,
  kADMSetPlaybackDeviceMute,
  kADMGetPlaybackDeviceMute,
  kADMStartPlaybackDeviceTest,
  kADMStopPlaybackDeviceTest,

  kADMEnumerateRecordingDevices,
  kADMSetRecordingDevice,
  kADMGetRecordingDevice,
  kADMGetRecordingDeviceInfo,
  kADMSetRecordingDeviceVolume,
  kADMGetRecordingDeviceVolume,
  kADMSetRecordingDeviceMute,
  kADMGetRecordingDeviceMute,
  kADMStartRecordingDeviceTest,
  kADMStopRecordingDeviceTest,

  kADMStartAudioDeviceLoopbackTest,
  kADMStopAudioDeviceLoopbackTest,
};

enum ApiTypeVideoDeviceManager {
  kVDMEnumerateVideoDevices,
  kVDMSetDevice,
  kVDMGetDevice,
  kVDMStartDeviceTest,
  kVDMStopDeviceTest,
};

enum ApiTypeRawDataPluginManager {
  kRDPMRegisterPlugin,
  kRDPMUnregisterPlugin,
  kRDPMHasPlugin,
  kRDPMEnablePlugin,
  kRDPMGetPlugins,
  kRDPMSetPluginParameter,
  kRDPMGetPluginParameter,
  kRDPMRelease
};

enum AudioFrameType {
  kAudioFrameTypePCM16,
};

typedef struct IrisRtcAudioFrame {
  AudioFrameType type;
  int samples;
  int bytes_per_sample;
  int channels;
  int samples_per_sec;
  void *buffer;
  unsigned int buffer_length;
  int64_t render_time_ms;
  int av_sync_type;
} IrisRtcAudioFrame;

extern const struct IrisRtcAudioFrame IrisRtcAudioFrame_default;

IRIS_API void ResizeAudioFrame(IrisRtcAudioFrame *audio_frame);

IRIS_API void ClearAudioFrame(IrisRtcAudioFrame *audio_frame);

IRIS_API void CopyAudioFrame(IrisRtcAudioFrame *dst,
                             const IrisRtcAudioFrame *src);

enum VideoFrameType {
  kVideoFrameTypeYUV420,
  kVideoFrameTypeYUV422,
  kVideoFrameTypeRGBA,
  kVideoFrameTypeBGRA,
};

enum VideoObserverPosition {
  kPositionPostCapturer = 1 << 0,
  kPositionPreRenderer = 1 << 1,
  kPositionPreEncoder = 1 << 2,
};

typedef struct IrisRtcVideoFrame {
  VideoFrameType type;
  int width;
  int height;
  int y_stride;
  int u_stride;
  int v_stride;
  void *y_buffer;
  void *u_buffer;
  void *v_buffer;
  unsigned int y_buffer_length;
  unsigned int u_buffer_length;
  unsigned int v_buffer_length;
  int rotation;
  int64_t render_time_ms;
  int av_sync_type;
} IrisRtcVideoFrame;

extern const struct IrisRtcVideoFrame IrisRtcVideoFrame_default;

IRIS_API void ResizeVideoFrame(IrisRtcVideoFrame *video_frame);

IRIS_API void ClearVideoFrame(IrisRtcVideoFrame *video_frame);

IRIS_API void CopyVideoFrame(IrisRtcVideoFrame *dst,
                             const IrisRtcVideoFrame *src);

IRIS_API IrisRtcVideoFrame ConvertVideoFrame(const IrisRtcVideoFrame *src,
                                             VideoFrameType format);

typedef struct IrisRect {
  double x;
  double y;
  double width;
  double height;
} IrisRect;

typedef struct IrisDisplay {
  unsigned int id;
  float scale;
  IrisRect bounds;
  IrisRect work_area;
  int rotation;
} IrisDisplay;

typedef struct IrisDisplayCollection {
  IrisDisplay *displays;
  unsigned int length;
} IrisDisplayCollection;

typedef struct IrisWindow {
  unsigned long id;
  char name[kBasicResultLength];
  char owner_name[kBasicResultLength];
  IrisRect bounds;
  IrisRect work_area;
} IrisWindow;

typedef struct IrisWindowCollection {
  IrisWindow *windows;
  unsigned int length;
} IrisWindowCollection;

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE)                 \
    || defined(_WIN32)
IRIS_API IrisDisplayCollection *EnumerateDisplays();

IRIS_API void FreeIrisDisplayCollection(IrisDisplayCollection *collection);

IRIS_API IrisWindowCollection *EnumerateWindows();

IRIS_API void FreeIrisWindowCollection(IrisWindowCollection *collection);
#endif
#ifdef __cplusplus
}
#endif

#endif//IRIS_RTC_BASE_H_
