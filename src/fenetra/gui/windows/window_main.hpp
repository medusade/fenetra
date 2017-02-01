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
///   File: window_main.hpp
///
/// Author: $author$
///   Date: 6/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FENETRA_GUI_WINDOWS_WINDOW_MAIN_HPP
#define _FENETRA_GUI_WINDOWS_WINDOW_MAIN_HPP

#include "fenetra/gui/windows/main.hpp"
#include "fenetra/gui/windows/window_class.hpp"
#include "fenetra/gui/windows/main_window.hpp"

namespace fenetra {
namespace gui {
namespace windows {

typedef fenetra::gui::windows::main_implements window_main_implements;
typedef fenetra::gui::windows::main window_main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: window_maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = window_main_implements, class TExtends = window_main_extends>
class _EXPORT_CLASS window_maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    window_maint(): main_window_class_(0), main_window_(0) {
    }
    virtual ~window_maint() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_WinMainLoop
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 1;
        if ((main_window_class_ = (this->create_main_window_class
            (hInstance, hPrevInstance, cmdLine, cmdShow)))) {
            if ((main_window_ = (this->create_main_window
                (*main_window_class_, hInstance, hPrevInstance, cmdLine, cmdShow)))) {
                return err = 0;
            }
            this->destroy_main_window_class
            (*main_window_class_, hInstance, hPrevInstance, cmdLine, cmdShow);
        }
        return err;
    }
    virtual int after_WinMainLoop
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0;
        if ((main_window_)) {
            if (!(this->destroy_main_window
                (*main_window_, *main_window_class_, 
                 hInstance, hPrevInstance, cmdLine, cmdShow))) {
                err = 1;
            }
        } else {
            err = 1;
        }
        if ((main_window_class_)) {
            if (!(this->destroy_main_window_class
                (*main_window_class_, hInstance, hPrevInstance, cmdLine, cmdShow))) {
                err = 1;
            }
        } else {
            err = 1;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual window* create_main_window
    (window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         LPCSTR className = 0;
         if ((className = main_window_class.ClassName())) {
             if ((window_.create(hInstance, className))) {
                 return &window_;
             }
         }
         return 0;
    }
    virtual bool destroy_main_window
    (window& main_window, window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         if (&main_window == (&window_)) {
             if ((window_.destroy())) {
                 return true;
             }
         }
         return false;
    }
    virtual bool show_main_window
    (window& main_window, window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         if ((main_window.Show())) {
             return true;
         }
         return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual window_class* create_main_window_class
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        if ((window_class_.create_attached(hInstance))) {
            return &window_class_;
        }
        return 0;
    }
    virtual bool destroy_main_window_class
    (window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         if ((&main_window_class == (&window_class_))) {
             if ((window_class_.destroy())) {
                 return true;
             }
         }
         return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    window_class *main_window_class_, window_class_;
    window* main_window_;
    main_window window_;
};
typedef window_maint<> window_main;

} // namespace windows
} // namespace gui
} // namespace fenetra 

#endif // _FENETRA_GUI_WINDOWS_WINDOW_MAIN_HPP 
