///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: window_class.hpp
///
/// Author: $author$
///   Date: 6/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FENETRA_GUI_WINDOWS_WINDOW_CLASS_HPP
#define _FENETRA_GUI_WINDOWS_WINDOW_CLASS_HPP

#include "fenetra/gui/windows/message_target.hpp"
#include "fenetra/gui/windows/atom.hpp"

#define FENETRA_GUI_WINDOWS_WINDOW_CLASSNAME \
    "fenetra::gui::windows::window_class"

namespace fenetra {
namespace gui {
namespace windows {

typedef atom_implements window_class_implements;
typedef atom window_class_extends;
///////////////////////////////////////////////////////////////////////
///  Class: window_classt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = window_class_implements, class TExtends = window_class_extends>
class _EXPORT_CLASS window_classt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::attached_t attached_t;
    typedef typename Extends::unattached_t unattached_t;
    enum { unattached = typename Extends::unattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    window_classt
    (LPCSTR className = FENETRA_GUI_WINDOWS_WINDOW_CLASSNAME,
     WNDPROC wndProc = message_target::WindowProc,
     int windowExtra = (int)(sizeof(message_target*)),
     int windowExtraOffset = 0,
     int classExtra = 0,
     int classExtraOffset = 0,
     UINT style = 0,
     attached_t detached = ((attached_t)unattached), bool is_created = false)
    : Extends(detached, is_created),
      className_(className),
      wndProc_(wndProc),
      hBackgroundBrush_(0),
      hCursor_(0),
      windowExtra_(windowExtra),
      windowExtraOffset_(windowExtraOffset),
      classExtra_(classExtra),
      classExtraOffset_(classExtraOffset),
      style_(style) {
    }
    virtual ~window_classt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (HINSTANCE instance, LPCSTR classname = NULL, WNDPROC wndproc = NULL,
     LPCSTR menuname = NULL, HICON icon = NULL, HICON iconsm = NULL,
     HCURSOR cursor = NULL, HBRUSH background = NULL, UINT style = 0,
     int wndextra = -1, int clsextra = -1) {
        bool isSuccess = false;
        ATOM detached = 0;
        if ((detached = this->create_attached
            (instance, classname, wndproc, menuname, icon, iconsm, 
             cursor, background, style, wndextra, clsextra))) {
            this->set_is_created();
            isSuccess = true;
        }
        return isSuccess;
    }
    virtual bool destroy() {
        bool isSuccess = false;
        ATOM detached = 0;
        if ((detached = this->detach())) {
            isSuccess = destroy_detached(detached, wndClass_);
        }
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ATOM create_attached
    (HINSTANCE instance, LPCSTR classname = NULL, WNDPROC wndproc = NULL,
     LPCSTR menuname = NULL, HICON icon = NULL, HICON iconsm = NULL,
     HCURSOR cursor = NULL, HBRUSH background = NULL, UINT style = 0,
     int wndextra = -1, int clsextra = -1) {
        ATOM detached = NULL;
        if (!(this->destroyed())) {
            return NULL;
        }
        if (classname) {
            SetClassName(classname);
        } else {
            if (!(classname = this->ClassName())) {
                return NULL;
            }
        }
        if (!wndproc) {
            if (!(wndproc = this->WindowProc())) {
                return NULL;
            }
        }
        if (!background) {
            background = Background();
        }
        if (0 > wndextra) {
            wndextra = WindowExtra();
        }
        if (0 > clsextra) {
            clsextra = ClassExtra();
        }
        if (!style) {
            style = Style();
        }
        if ((detached = this->create_detached
            (wndClass_, instance, classname, wndproc, menuname, icon, 
             iconsm, cursor, background, style, wndextra, clsextra))) {
             this->attach(detached);
        }
        return detached;
    }
    virtual ATOM create_detached
    (WNDCLASSEXA& wndClass, 
     HINSTANCE instance, LPCSTR classname, WNDPROC wndproc = NULL,
     LPCSTR menuname = NULL, HICON icon = NULL, HICON iconsm = NULL,
     HCURSOR cursor = NULL, HBRUSH background = NULL, UINT style = 0,
     int wndextra = 0, int clsextra = 0, bool isInitial = false) const {
        ATOM detached = NULL;

        memset(&wndClass, 0, sizeof(WNDCLASSEXA));
        wndClass.cbSize = sizeof(WNDCLASSEXA);
        wndClass.hInstance = instance;
        wndClass.lpszClassName = classname;
        wndClass.style = style;
        wndClass.cbClsExtra = clsextra;
        wndClass.cbWndExtra = wndextra;

        if ((NULL != menuname) || isInitial) {
            wndClass.lpszMenuName = menuname;
        }
        if ((NULL != icon) || isInitial) {
            wndClass.hIcon = icon;
        }
        if ((NULL != iconsm) || isInitial) {
            wndClass.hIconSm = iconsm;
        }
        if ((NULL != cursor) || isInitial) {
            wndClass.hCursor = cursor;
        } else {
            if (NULL == wndClass.hCursor) {
                wndClass.hCursor = this->DefaultCursor();
            }
        }
        if ((NULL != background) || isInitial) {
            wndClass.hbrBackground = background;
        } else { 
            if (NULL == wndClass.hbrBackground) {
                wndClass.hbrBackground = this->DefaultBackground();
            }
        }
        if ((NULL != wndproc) || isInitial) {
            wndClass.lpfnWndProc = wndproc;
        } else {
            if (NULL == wndClass.lpfnWndProc) {
                wndClass.lpfnWndProc = this->DefaultWindowProc();
            }
        }
        if (!(NULL != (detached = RegisterClassExA(&wndClass)))) {
            DWORD dwError = GetLastError();
            FENETRA_LOG_ERROR("...failed " << dwError << " on RegisterClassExA()");
        }
        return detached;
    }
    virtual bool destroy_detached
    (ATOM detached, const WNDCLASSEXA& wndClass) const {
        bool isSuccess = false;
        if ((detached)) {
            if (!(isSuccess = !(TRUE != (UnregisterClassA
                (wndClass.lpszClassName, wndClass.hInstance))))) {
                DWORD dwError = GetLastError();
                FENETRA_LOG_ERROR("...failed " << dwError << " on UnregisterClass()");
            }
        }
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual LPCSTR SetClassName(LPCSTR chars) {
        className_.assign(chars);
        return className_.chars();
    }
    virtual LPCSTR ClassName() const {
        return className_.chars();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual WNDPROC SetWindowProc(WNDPROC wndProc) {
        wndProc_ = wndProc;
        return wndProc_;
    }
    virtual WNDPROC WindowProc() const {
        return wndProc_;
    }
    virtual WNDPROC DefaultWindowProc() const {
        WNDPROC wndproc = DefWindowProc;
        return wndproc;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int SetWindowExtra(int bytes) {
        windowExtra_ = bytes;
        return windowExtra_;
    }
    virtual int WindowExtra() const {
        return windowExtra_;
    }
    virtual int SetWindowExtraOffset(int bytes) {
        windowExtraOffset_ = bytes;
        return windowExtraOffset_;
    }
    virtual int WindowExtraOffset() const {
        return windowExtraOffset_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int SetClassExtra(int bytes) {
        classExtra_ = bytes;
        return classExtra_;
    }
    virtual int ClassExtra() const {
        return classExtra_;
    }
    virtual int SetClassExtraOffset(int bytes) {
        classExtraOffset_ = bytes;
        return classExtraOffset_;
    }
    virtual int ClassExtraOffset() const {
        return classExtraOffset_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HBRUSH SetBackground(HBRUSH hBrush) {
        hBackgroundBrush_ = hBrush;
        return hBackgroundBrush_;
    }
    virtual HBRUSH Background() const {
        return hBackgroundBrush_;
    }
    virtual HBRUSH DefaultBackground() const {
        HBRUSH handle = (HBRUSH)GetStockObject(WHITE_BRUSH);
        return handle;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HCURSOR SetCursor(HCURSOR hCursor) {
        hCursor_ = hCursor;
        return hCursor_;
    }
    virtual HCURSOR Cursor() const {
        return hCursor_;
    }
    virtual HCURSOR DefaultCursor() const {
        HCURSOR handle = LoadCursor(NULL, IDC_ARROW);
        return handle;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual UINT SetStyle(UINT toStyle) {
        style_ = (toStyle);
        return style_;
    }
    virtual UINT Style() const {
        return style_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static LPCSTR DefaultClassName() {
        static LPCSTR chars = FENETRA_GUI_WINDOWS_WINDOW_CLASSNAME;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string className_;
    WNDPROC wndProc_;
    HBRUSH hBackgroundBrush_;
    HCURSOR hCursor_;
    int windowExtra_;
    int windowExtraOffset_;
    int classExtra_;
    int classExtraOffset_;
    UINT style_;
    WNDCLASSEXA wndClass_;
};
typedef window_classt<> window_class;

} // namespace windows
} // namespace gui
} // namespace fenetra 

#endif // _FENETRA_GUI_WINDOWS_WINDOW_CLASS_HPP 
