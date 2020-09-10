const char AWS_IOT_ENDPOINT[] = "<<YOUR AWS IOT CORE ENDPOINT, ex.:a2p4fyajwx9lux-ats.iot.us-east-1.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
<<YOUR ROOT-CA CERTIFICATE HERE>>
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
<<YOUR DEVICE CERTIFICATE HERE>>
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
<<YOUR PRIVATE KEY HERE>>
-----END RSA PRIVATE KEY-----
)KEY";
