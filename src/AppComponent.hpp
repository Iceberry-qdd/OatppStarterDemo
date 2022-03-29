#ifndef AppComponent_hpp
#define AppComponent_hpp

#include "oatpp/web/server/HttpConnectionHandler.hpp"

#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "oatpp/core/macro/component.hpp"

class AppComponent
{
public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)([]{
        return oatpp::network::tcp::server::ConnectionProvider::createShared({"0.0.0.0", 8000, oatpp::network::Address::IP_4});
    }());

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)
    ([]
     { return oatpp::web::server::HttpRouter::createShared(); }());

    /**
     *  Create ConnectionHandler component which uses Router component to route requests
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)
    ([]
     {
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router); // get Router component
    return oatpp::web::server::HttpConnectionHandler::createShared(router); }());

    /**
     *  Create ObjectMapper component to serialize/deserialize DTOs in Contoller's API
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)
    ([]
     { return oatpp::parser::json::mapping::ObjectMapper::createShared(); }());
};

#endif /* AppComponent_hpp */