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
///   File: WinMain.cpp
///
/// Author: $author$
///   Date: 6/13/2016
///////////////////////////////////////////////////////////////////////
#include "fenetra/gui/windows/WinMain.hpp"
#include "fenetra/gui/windows/main.cpp"

namespace fenetra {
namespace gui {
namespace windows {
} // namespace windows
} // namespace gui
} // namespace fenetra 

///////////////////////////////////////////////////////////////////////
/// Function: WinMain
///////////////////////////////////////////////////////////////////////
int WINAPI WinMain
(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
    int err = fenetra::gui::windows::main::the_WinMain
    (hInstance, hPrevInstance, cmdLine, cmdShow);
    return err;
}
