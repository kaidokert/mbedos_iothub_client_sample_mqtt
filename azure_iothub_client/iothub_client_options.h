// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef IOTHUB_CLIENT_OPTIONS_H
#define IOTHUB_CLIENT_OPTIONS_H

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct IOTHUB_PROXY_OPTIONS_TAG
    {
        const char* host_address;
        const char* username;
        const char* password;
    } IOTHUB_PROXY_OPTIONS;

    static const char* OPTION_LOG_TRACE = "logtrace";
    static const char* OPTION_X509_CERT = "x509certificate";
    static const char* OPTION_X509_PRIVATE_KEY = "x509privatekey";
    static const char* OPTION_KEEP_ALIVE = "keepalive";
    static const char* OPTION_CONNECTION_TIMEOUT = "connect_timeout";

    static const char* OPTION_PROXY_HOST = "proxy_address";
    static const char* OPTION_PROXY_USERNAME = "proxy_username";
    static const char* OPTION_PROXY_PASSWORD = "proxy_password";

    static const char* OPTION_SAS_TOKEN_LIFETIME = "sas_token_lifetime";
    static const char* OPTION_SAS_TOKEN_REFRESH_TIME = "sas_token_refresh_time";
    static const char* OPTION_CBS_REQUEST_TIMEOUT = "cbs_request_timeout";

    static const char* OPTION_MIN_POLLING_TIME = "MinimumPollingTime";
    static const char* OPTION_BATCHING = "Batching";

    static const char* OPTION_MESSAGE_TIMEOUT = "messageTimeout";
    static const char* OPTION_PRODUCT_INFO = "product_info";
    /*
    * @brief Informs the service of what is the maximum period the client will wait for a keep-alive message from the service.
    *        The service must send keep-alives before this timeout is reached, otherwise the client will trigger its re-connection logic.
    *        Setting this option to a low value results in more aggressive/responsive re-connection by the client.
    *        The default value for this option is 240 seconds, and the minimum allowed is usually 5 seconds.
    *        To virtually disable the keep-alives from the service (and consequently the keep-alive timeout control on the client-side), set this option to a high value (e.g., UINT_MAX).
    */
    static const char* OPTION_SERVICE_SIDE_KEEP_ALIVE_FREQ_SECS = "svc2cl_keep_alive_timeout_secs";

	/*
	* @brief Ratio to be used for client side pings in AMQP protocol.
	*        The client must use this ratio to send keep-alives before service side remote idle timeout is reached, otherwise the service will disconnect the client.
	*        The default value for this option is 1/2 of the remote idle value sent by the service. 
	*        For AMQP remote idle set to 4 minutes, default client ping will be 2 minutes. For AMQP remote idle set to 25 minutes configured via per Hub basis, the default ping will be 12.5 minutes.
	*/
	static const char* OPTION_REMOTE_IDLE_TIMEOUT_RATIO = "cl2svc_keep_alive_send_ratio"; 

    //diagnostic sampling percentage value, [0-100]
    static const char* OPTION_DIAGNOSTIC_SAMPLING_PERCENTAGE = "diag_sampling_percentage";

#ifdef __cplusplus
}
#endif

#endif /* IOTHUB_CLIENT_OPTIONS_H */
