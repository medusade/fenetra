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
///   File: hwnd.hpp
///
/// Author: $author$
///   Date: 6/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FENETRA_GUI_WINDOWS_HWND_HPP
#define _FENETRA_GUI_WINDOWS_HWND_HPP

#include "fenetra/base/base.hpp"
#include "fenetra/io/logger.hpp"

namespace fenetra {
namespace gui {
namespace windows {

typedef HWND hwnd_attached_t;
typedef xos::base::creatort<implement_base> hwnd_creator;
typedef xos::base::attachert
<hwnd_attached_t, int, 0, hwnd_creator> hwnd_attacher;
typedef xos::base::attachedt
<hwnd_attached_t, int, 0, hwnd_attacher, base> hwnd_attached;
typedef xos::base::createdt
<hwnd_attached_t, int, 0, hwnd_attacher, hwnd_attached> hwnd_created;
///////////////////////////////////////////////////////////////////////
///  Class: hwnd_implementt
///////////////////////////////////////////////////////////////////////
template <class TImplements = hwnd_attacher>
class _EXPORT_CLASS hwnd_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HINSTANCE attach_instance(HINSTANCE instance) {
        return 0;
    }
    virtual HINSTANCE attached_to_instance() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef hwnd_implementt<> hwnd_implement;
typedef hwnd_implement hwnd_implements;
typedef hwnd_created hwnd_extends;
///////////////////////////////////////////////////////////////////////
///  Class: hwndt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = hwnd_implements, class TExtends = hwnd_extends>
class _EXPORT_CLASS hwndt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::attached_t attached_t;
    typedef typename Extends::unattached_t unattached_t;
    enum { unattached = typename Extends::unattached };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    hwndt(HINSTANCE instance = 0, HWND detached = 0, bool is_created = false)
    : Extends(detached, is_created), 
      instance_(instance), was_destroyed_(false) {
    }
    hwndt(const hwndt& copy)
    : Extends(copy), 
      instance_(copy.instance_), was_destroyed_(copy.was_destroyed_) {
    }
    virtual ~hwndt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HWND attach_created
    (HINSTANCE instance, HWND detached, bool is_created = true) {
        Extends::attach_created(detached, is_created);
        instance_ = instance;
        return this->attached_to();
    }
    virtual HWND detach_created(HINSTANCE& instance, bool& is_created) {
        instance = instance_;
        return Extends::detach_created(is_created);
    }
    virtual HWND detach_created(bool& is_created) {
        instance_ = 0;
        return Extends::detach_created(is_created);
    }
    virtual HWND detach() {
        instance_ = 0;
        return Extends::detach();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HINSTANCE attach_instance(HINSTANCE instance) {
        instance_ = instance;
        return instance_;
    }
    virtual HINSTANCE attached_to_instance() const {
        return instance_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_was_destroyed(bool to = true) {
        was_destroyed_ = to;
        return was_destroyed_;
    }
    virtual bool was_destroyed() const {
        return was_destroyed_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    HINSTANCE instance_;
    bool was_destroyed_;
};
typedef hwndt<> hwnd;

} // namespace windows
} // namespace gui
} // namespace fenetra 

#endif // _FENETRA_GUI_WINDOWS_HWND_HPP 
