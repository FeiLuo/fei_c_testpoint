#ifndef _PCAP_H__
#define _PCAP_H__

#define PCAP_VERSION_MAJOR      2
#define PCAP_VERSION_MINOR      4

#define PCAP_STANDARD_MAGIC     0xa1b2c3d4
#define PCAP_PATCHED_MAGIC      0xa1b2cd34

#define PCAP_SNAPLENGTH         0xFFFF
#define PCAP_LINKTYPE           1

// PCAP File Header structure
typedef struct PCapFileHeader_t 
{
    Uint32        Magic;
    Uint16        VersionMajor;
    Uint16        VersionMinor;
    Int32         TZone;                  // gmt to local correction
    Uint32        SigFigs;                // accuracy of timestamps
    Uint32        SnapLength;             // max length saved portion of each pkt
    Uint32        LinkType;               // data link type (LINKTYPE_*)
} PCapFileHeader;

// Standard PCap record
typedef struct StandardPCapRecordHeader_t 
{
    // Could replace seconds and microseconds with struct timeval on most OSs.
    // struct timeval timeStamp;    // Time stamp
    Uint32 seconds;              // Seconds
    Uint32 microseconds;         // Microseconds
    Uint32 captureLength;        // Length of portion present
    Uint32 packetLength;         // Actual length of this packet (off media)
} StandardPCapRecordHeader;

// Patched PCap record extension
typedef struct PatchedPCapRecordHeaderExt_t 
{
    Int32   index;
    Uint16  protocol;
    Uint8   packetType;
} PatchedPCapRecordHeaderExt;

#define ETHER_IP 0x0800
#define ETHER_ARP 0x0806

// Ethernet header
typedef struct EthernetHeader_t 
{
    Uint8 destination[6];    // Destination MAC address
    Uint8 source[6];         // Source MAC address
    Uint16 type;             // IP, ARP, etc
} EthernetHeader;

// ARP header
typedef struct ARPHeader_t
{
    Uint16 hardwareAddressType;
    Uint16 protocolAddressType;
    Uint8 hardwareAddressLength;
    Uint8 protocolAddressLength;
    Uint16 opcode;
} ARPHeader;

#define IP_ICMP 1
#define IP_TCP 6
#define IP_UDP 17

// IP header
typedef struct IPHeader_t 
{
#if IS_LITTLE_ENDIAN
    Uint8   headerLength:4;
    Uint8   version:4;
#else
    Uint8   version:4;
    Uint8   headerLength:4;
#endif
    Uint8   typeOfService;
    Uint16  length;
    Uint16  id;               // Identification
    Uint16  offset;           // Fragment offset field
    Uint8   timeToLive;
    Uint8   protocol;
    Uint16  checksum;
    Uint32  source;           // Source IP address
    Uint32  destination;      // Destination IP address
} IPHeader;

// ICMP Header
typedef struct ICMPHeader_t 
{
    Uint8 type;
    Uint8 code;              // Type Subcode
    Uint16 checksum;
    union 
    {
        // Echo datagram
        struct 
        {
            Uint16 id;       // Identifier
            Uint16 sequence;
        } echo;
        Uint32 gateway;      // Gateway address
        // Path MTU discovery
        struct
        {
            Uint16 unused;
            Uint16 mtu;
        } frag;
    } content;
} ICMPHeader;

// TCP header
typedef struct TCPHeader_t 
{
    Uint16  srcPort;          // Source port
    Uint16  destPort;         // Destination port
    Uint32  sequence;         // Sequence number
    Uint32  ack;              // Acknowledgement number
#if IS_LITTLE_ENDIAN
    Uint8   unused:4;
    Uint8   offset:4;          // Data offset
#else
    Uint8   offset:4;
    Uint8   unused:4;
#endif
    Uint8   flags;
    Uint16  window;
    Uint16  checksum;
    Uint16  urgentPointer;
} TCPHeader;

// UDP Header
typedef struct UDPHeader_t 
{
    Uint16 srcPort;          // Source port
    Uint16 destPort;         // Destination port
    Uint16 length;
    Uint16 checksum;
} UDPHeader;


#endif /* _PCAP_H__ */
