#include "files.h"
#include "cryptlib.h"
#include "filters.h"    // StringSink
#include "osrng.h"      // AutoSeededRandomPool
#include "hex.h"        // HexEncoder

#include <iostream>
#include <string>
#include <bitset>

#include "sha256.h"

using namespace std;
using namespace CryptoPP;


string sha256(const string& s) {
    SHA256 hash = SHA256();
    byte const* pbData = (byte const*) s.data();
    unsigned int nDataLen = s.size();
    SecByteBlock sbbDigest(hash.DigestSize());

    hash.CalculateDigest(sbbDigest.begin(), pbData, nDataLen);

    if (!hash.VerifyDigest(sbbDigest, pbData, nDataLen))
        throw "abDigest does not contain the right hash";

    // Convert digest to hex string
    string hashCode;
    HexEncoder(new StringSink(hashCode)).Put(sbbDigest.begin(), sbbDigest.size());

    return hashCode;
}