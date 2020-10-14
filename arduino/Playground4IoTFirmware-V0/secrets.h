const char AWS_IOT_ENDPOINT[] = "<YOUR ENDPOINT HERE>";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
<COPY AND PASTE HERE>
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
<COPY AND PASTE HERE>
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
<COPY AND PASTE HERE>
-----END RSA PRIVATE KEY-----
)KEY";
