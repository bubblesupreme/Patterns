
package Response;

public class ResponseLine {
    public String protocol_version;
    public int status;
    public String reason_phrase;

    public ResponseLine(String protocol_version, int status, String reason_phrase) {
        this.protocol_version = protocol_version;
        this.status = status;
        this.reason_phrase = reason_phrase;
    }

    @Override
    public String toString()
    {
        return protocol_version+" "+status+" "+reason_phrase;
    }
}
