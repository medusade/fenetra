///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 1/30/2017
///////////////////////////////////////////////////////////////////////
#ifndef _FENETRA_WINDOWS_MAIN_HPP
#define _FENETRA_WINDOWS_MAIN_HPP

#include "fenetra/windows/Base.hpp"

namespace fenetra {
namespace windows {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum SingletonStatus {
	SingletonSuccess,
	SingletonDuplicated,
	SingletonMissing,
	SingletonInvalid
};

typedef ImplementBase MainTImplements;
typedef Base MainTExtends;
///////////////////////////////////////////////////////////////////////
/// Class: MainT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainTImplements, class TExtends = MainTExtends>
class _EXPORT_CLASS SingletonExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	SingletonExceptionT(SingletonStatus status): m_status(status) {
    }
    virtual ~SingletonExceptionT() {
    }
	virtual SingletonStatus Status() const { return m_status; }
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
protected:
	SingletonStatus m_status;
};
typedef SingletonExceptionT<> SingletonException;

///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template <class TImplements =ImplementBase, class TExtends = Base>
class _EXPORT_CLASS MainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
    MainT() {
		MainT*& theMain = TheMain();
		if (!(theMain)) {
			theMain = this;
		} else {
			SingletonException e(SingletonDuplicated);
			LOG_ERROR("...throw SingletonException e(SingletonDuplicated)...");
			throw (e);
		}
    }
    virtual ~MainT() {
		MainT* theMain = TheMain();
		if ((theMain)) {
			if ((theMain == this)) {
				theMain = 0;
			} else {
				SingletonException e(SingletonInvalid);
				LOG_ERROR("...throw SingletonException e(SingletonInvalid)...");
				throw (e);
			}
		} else {
			SingletonException e(SingletonMissing);
			LOG_ERROR("...throw SingletonException e(SingletonMissing)...");
			throw (e);
		}
    }

protected:
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	virtual int operator()
	(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
		int err = 0;
		return err;
	}

public:
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	static int WinMain
	(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
		int err = 1;
		MainT* theMain = 0;
		if ((theMain = TheMain())) {
			err = (*theMain)(hInstance, hPrevInstance, cmdLine, cmdShow);
		}
		return err;
	}
protected:
	static MainT*& TheMain() {
		static MainT* theMain = 0;
		return theMain;
	}

	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
};
typedef MainT<> Main;

} // namespace windows 
} // namespace fenetra 

#endif // _FENETRA_WINDOWS_MAIN_HPP 
