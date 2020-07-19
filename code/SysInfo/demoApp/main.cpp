#include <SysInfo/InfoPresenter.h>


int main() {
    RRLibs::SysInfo::InfoPresenter presenter;
    presenter.show(RRLibs::SysInfo::InfoPresenter::All, true);

    presenter.show(RRLibs::SysInfo::InfoPresenter::All, false);
    return 0;
}