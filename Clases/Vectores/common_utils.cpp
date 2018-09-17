#include "common_utils.h"

string toString(bool b) {
    return b ? "true" : "false";
}

string testStatus(bool success) {
    return success ? "-==| SUCCESS |==-" : "!!! --- FAILURE --- !!!";
}