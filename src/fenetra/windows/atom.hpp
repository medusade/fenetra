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
///   File: atom.hpp
///
/// Author: $author$
///   Date: 6/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FENETRA_WINDOWS_ATOM_HPP
#define _FENETRA_WINDOWS_ATOM_HPP

#include "fenetra/base/base.hpp"

namespace fenetra {
namespace windows {

typedef ATOM atom_attached_t;
typedef xos::base::creatort<implement_base> atom_creator;
typedef xos::base::attachert<atom_attached_t, int, 0, atom_creator> atom_attacher;
typedef xos::base::attachedt<atom_attached_t, int, 0, atom_attacher, base> atom_attached;
typedef xos::base::createdt<atom_attached_t, int, 0, atom_attacher, atom_attached> atom_created;
typedef atom_attacher atom_implements;
typedef atom_created atom_extends;
///////////////////////////////////////////////////////////////////////
///  Class: atomt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = atom_implements, class TExtends = atom_extends>
class _EXPORT_CLASS atomt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    typedef typename Extends::unattached_t unattached_t;
    enum { unattached = typename Extends::unattached };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    atomt(attached_t detached = ((attached_t)unattached), bool is_created = false)
    : Extends(detached, is_created) {
    }
    atomt(const atomt& copy)
    : Extends(copy.attached_to(), copy.is_created()) {
    }
    virtual ~atomt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef atomt<> atom;

} // namespace windows 
} // namespace fenetra 


#endif // _FENETRA_WINDOWS_ATOM_HPP 
        

