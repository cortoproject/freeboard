/* This is a managed file. Do not delete this comment. */

#include <freeboard/freeboard.h>

int16_t freeboard_service_construct(
    freeboard_service this)
{
    corto_ptr_setstr(&httpserver_Files(this)->path, FREEBOARD_ETC);
    return corto_super_construct(this);
}

