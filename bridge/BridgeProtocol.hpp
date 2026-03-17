#ifndef BRIDGE_PROTOCOL_HPP
#define BRIDGE_PROTOCOL_HPP

#include <cstdint>

namespace BridgeProtocol {

// Magic number for packet validation
constexpr uint32_t MAGIC = 0xDEC0D10A;

// Default ports
constexpr uint16_t WEBSOCKET_PORT = 52178;
constexpr uint16_t DISCOVERY_PORT = 52179;

// Audio parameters
constexpr unsigned RX_SAMPLE_RATE = 12000;   // Downsampled RX
constexpr unsigned TX_SAMPLE_RATE = 48000;   // Full-rate TX
constexpr unsigned RX_CHUNK_MS    = 40;      // 40ms chunks
constexpr unsigned RX_CHUNK_SAMPLES = RX_SAMPLE_RATE * RX_CHUNK_MS / 1000; // 480
constexpr unsigned TX_CHUNK_SAMPLES = 1920;  // 40ms at 48kHz

// Message types
enum MessageType : uint8_t {
    AUDIO_RX    = 0x01,  // PC → Phone: PCM Int16 mono 12kHz
    AUDIO_TX    = 0x02,  // Phone → PC: PCM Int16 mono 48kHz
    CAT_FREQ    = 0x03,  // Phone → PC: uint64 freq Hz
    CAT_MODE    = 0x04,  // Phone → PC: utf8 mode string
    CAT_PTT     = 0x05,  // Phone → PC: uint8 ptt on/off
    CAT_STATUS  = 0x06,  // PC → Phone: freq + mode + ptt + s-meter
    SPECTRUM    = 0x07,  // PC → Phone: float32[] FFT bins
    HEARTBEAT   = 0x08,  // Bidirectional: uint32 timestamp
};

// Packet header (8 bytes)
#pragma pack(push, 1)
struct PacketHeader {
    uint32_t magic;      // MAGIC
    uint8_t  type;       // MessageType
    uint8_t  reserved;
    uint16_t payloadSize; // bytes of payload following header
};

// CAT status payload
struct CatStatusPayload {
    uint64_t frequency;  // Hz
    uint8_t  mode;       // index into mode list
    uint8_t  ptt;        // 0=off, 1=on
    int16_t  sMeter;     // S-meter value (dB * 10)
};
#pragma pack(pop)

// Discovery beacon message (UDP broadcast)
constexpr char DISCOVERY_MAGIC[] = "DECODIUM_BRIDGE";

} // namespace BridgeProtocol

#endif // BRIDGE_PROTOCOL_HPP
