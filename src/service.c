/* This is a managed file. Do not delete this comment. */

#include <freeboard/freeboard.h>

int16_t freeboard_service_construct(
    freeboard_service this)
{
    corto_set_str(&httprouter_service(this)->path, FREEBOARD_ETC);
    return corto_super_construct(this);
}

corto_string freeboard_service_config(
    freeboard_service this,
    httpserver_HTTP_Request *request,
    freeboard_config *data)
{
    return corto_strdup(this->config_url);
}

corto_string freeboard_service_home(
    freeboard_service this,
    httpserver_HTTP_Request *request,
    freeboard_home *data)
{
    return httprouter_route_defaultAction(freeboard_service_home_o, this, request);
}

corto_string freeboard_service_res(
    freeboard_service this,
    httpserver_HTTP_Request *request,
    freeboard_res *data)
{
    return httprouter_route_fileAction(freeboard_service_res_o, this, request, NULL, data->file);
}
