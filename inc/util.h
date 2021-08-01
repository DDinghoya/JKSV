#ifndef UTIL_H
#define UTIL_H

#include "data.h"
#include "ui.h"
#include "file.h"
#include "gfx.h"

namespace util
{
    enum
    {
        DATE_FMT_YMD,
        DATE_FMT_YDM,
        DATE_FMT_HOYSTE,
        DATE_FMT_JHK,
        DATE_FMT_ASC
    };

    //Returns string with date S+ time
    std::string getDateTime(int fmt);

    //Copys dir list to a menu with 'D: ' + 'F: '
    void copyDirListToMenu(const fs::dirList& d, ui::menu& m);

    //Removes last folder from '_path'
    void removeLastFolderFromString(std::string& _path);

    std::string safeString(const std::string& s);

    std::string getInfoString(const data::user& u, const data::titledata& d);

    std::string getStringInput(const std::string& def, const std::string& head, size_t maxLength, unsigned dictCnt, const std::string dictWords[]);

    std::string generateAbbrev(const data::titledata& dat);

    //removes char from C++ string
    void stripChar(char _c, std::string& _s);
    void replaceStr(std::string& _str, const std::string& _find, const std::string& _rep);

    //For future external translation support. Replaces [button] with button chars
    void replaceButtonsInString(std::string& rep);

    //Creates a basic generic icon for stuff without one
    SDL_Texture *createIconGeneric(const char *txt, int fontSize);

    inline u128 accountUIDToU128(AccountUid uid)
    {
        return ((u128)uid.uid[0] << 64 | uid.uid[1]);
    }

    inline AccountUid u128ToAccountUID(u128 id)
    {
        AccountUid ret;
        ret.uid[0] = id >> 64;
        ret.uid[1] = id;
        return ret;
    }

    void setCPU(uint32_t hz);
    void checkForUpdate();
}
#endif // UTIL_H
