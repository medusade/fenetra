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
///   File: main.hpp
///
/// Author: $author$
///   Date: 6/12/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FENETRA_GUI_WINDOWS_MAIN_HPP
#define _FENETRA_GUI_WINDOWS_MAIN_HPP

#include "fenetra/base/base.hpp"

namespace fenetra {
namespace gui {
namespace windows {

typedef xos::mt::locker main_locker;
typedef main_locker* main_attached_t;

typedef main_locker main_implements;
typedef xos::base::attachert<main_attached_t, int, 0, main_implements> main_attacher;
typedef xos::base::attachedt<main_attached_t, int, 0, main_attacher, base> main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>
class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint(): the_main_(the_main()) {
        the_main() = this;
    }
    virtual ~maint() {
        if ((this == the_main())) {
            the_main() = the_main_;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int the_WinMain
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow);

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int WinMain
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0;
        if (!(err = before_WinMainLoop
            (hInstance, hPrevInstance, cmdLine, cmdShow))) {
            int err2  = 0;

            err = WinMainLoop
            (hInstance, hPrevInstance, cmdLine, cmdShow);

            if ((err2 = after_WinMainLoop
               (hInstance, hPrevInstance, cmdLine, cmdShow))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int before_WinMain
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0;
        return err;
    }
    virtual int after_WinMain
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int WinMainLoop
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0;
        MSG msg;
        while ((this->GetMessage(&msg, NULL, 0,0))) {
            this->TranslateMessage(&msg);
            this->DispatchMessage(&msg);
        }
        return err;
    }
    virtual int before_WinMainLoop
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0;
        return err;
    }
    virtual int after_WinMainLoop
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual BOOL GetMessage
    (LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax) {
        if ((::GetMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax))) {
            return TRUE;
        }
        return FALSE;
    }
    virtual BOOL TranslateMessage(CONST MSG* lpMsg) {
        if ((::TranslateMessage(lpMsg))) {
            return TRUE;
        }
        return FALSE;
    }
    virtual LRESULT DispatchMessage(CONST MSG* lpMsg) {
        LRESULT lResult = 0;
        if ((lResult = ::DispatchMessage(lpMsg))) {
            return lResult;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int operator ()
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0, err2 = 0;
        if (!(err = before_WinMain(hInstance, hPrevInstance, cmdLine, cmdShow))) {
            err = WinMain(hInstance, hPrevInstance, cmdLine, cmdShow);
            if ((err2 = after_WinMain(hInstance, hPrevInstance, cmdLine, cmdShow))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t logfv(const char_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t log(const char_t* out, ssize_t length = -1) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t logln() {
        ssize_t count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool unlock() {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->unlock();
        }
        return true;
    }
    virtual bool lock() {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->lock();
        }
        return true;
    }
    virtual xos::mt::wait_status try_lock() {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->try_lock();
        }
        return xos::mt::wait_success;
    }
    virtual xos::mt::wait_status timed_lock(mseconds_t milliseconds) {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->timed_lock(milliseconds);
        }
        return xos::mt::wait_success;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static maint*& the_main();

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    maint* the_main_;
};
typedef maint<> main;

} // namespace windows
} // namespace gui
} // namespace fenetra 

#endif // _FENETRA_GUI_WINDOWS_MAIN_HPP 
