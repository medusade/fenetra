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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 1/29/2017
///////////////////////////////////////////////////////////////////////
#ifndef _FENETRA_WINDOWS_BASE_HPP
#define _FENETRA_WINDOWS_BASE_HPP

#include "nadir/base/base.hpp"
#include "nadir/base/attached.hpp"
#include "nadir/base/created.hpp"
#include "nadir/base/opened.hpp"
#include "nadir/base/acquired.hpp"
#include "nadir/base/locked.hpp"
#include "nadir/base/chars.hpp"
#include "nadir/base/string.hpp"
#include "nadir/base/array.hpp"
#include "nadir/io/logger.hpp"

namespace fenetra {
namespace windows {

typedef nadir::implement_base ImplementBase;
typedef nadir::base Base;

typedef nadir::chars_t Chars;
typedef nadir::tchars_t TChars;
typedef nadir::wchars_t WChars;

typedef nadir::char_string String;
typedef nadir::tchar_string TString;
typedef nadir::wchar_string WString;

typedef nadir::char_array CharArray;
typedef nadir::tchar_array TCharArray;
typedef nadir::wchar_array WCharArray;

} // namespace windows 
} // namespace fenetra 

#endif // _FENETRA_WINDOWS_BASE_HPP 
