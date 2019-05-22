
package Response;

public class ResponseLine {
    public String protocolVersion;
    public int status;
    public String reasonPhrase;

    public ResponseLine(String protocol_version, int status, String reason_phrase) {
        this.protocolVersion = protocol_version;
        this.status = status;
        this.reasonPhrase = reason_phrase;
    }

    @Override
    public String toString()
    {
        return protocolVersion+" "+status+" "+reasonPhrase;
    }
}
