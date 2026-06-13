//------------------------------------------------------------------------
// Project     : WebView host extensions (VST3 SDK extension)
//
// Category    : Helpers
// Filename    : pluginterfaces/vst/iwebview_aaxhostextensions.h
// Description : WebView-focused host extensions implemented by Steinberg's AAX wrapper
//
// NOTE:
// This is NOT part of the Steinberg VST3 SDK API. When using a WebView the Steinberg
// VST3->AAX wrapper needs a tiny custom hook so the wrapped VST3 instance
// can ask the wrapper to trigger Pro Tools GUI behaviors (e.g. automation menu).
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
/** WebView AAX host extensions
\ingroup vstIHost
- [host imp]
- [internal]

Implemented by the Steinberg VST3->AAX wrapper (AAXWrapper). When a VST3 plug-in is
running inside that wrapper it can query this interface from its IComponentHandler.
*/
class IWebViewAAXHostExtensions : public FUnknown
{
public:
	/** Request the Pro Tools parameter automation popup menu for the given VST3 ParamID.
	    \return kResultTrue when the request was accepted, otherwise kResultFalse. */
	virtual tresult PLUGIN_API openAutomationMenu (ParamID paramId) = 0;

	/** Request that Pro Tools shows the parameter's automation lane in the timeline/edit view.
	    This mirrors the Pro Tools gesture "Cmd+Ctrl+Click" on macOS ("Ctrl+Start+Click" on Windows).
	    \return kResultTrue when the request was accepted, otherwise kResultFalse. */
	virtual tresult PLUGIN_API openAutomationLane (ParamID paramId) = 0;

	/** Begin a Pro Tools parameter gesture for temporarily linking multi-mono channels while editing.
	    This mirrors the Pro Tools gesture "Shift+Click/Drag" on an automatable parameter.
	    \return kResultTrue when the request was accepted, otherwise kResultFalse. */
	virtual tresult PLUGIN_API beginMultiMonoLink (ParamID paramId) = 0;

	/** End a Pro Tools parameter gesture started via beginMultiMonoLink(). */
	virtual tresult PLUGIN_API endMultiMonoLink (ParamID paramId) = 0;

	//------------------------------------------------------------------------
	static inline const FUID iid = FUID (0x2C7C3A8E, 0x6C1B4C33, 0xA4C6B7B4, 0x1E2D9F0A);
};

} // namespace Vst
} // namespace Steinberg
