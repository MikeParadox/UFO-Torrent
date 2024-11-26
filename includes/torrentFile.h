#ifndef TORRENTFILE_H
#define TORRENTFILE_H

#include <boost/variant.hpp>
#include <ctime>
#include <optional>
#include <stdexcept>
#include "valueTypes.h"

using std::string;
using std::vector;
using std::optional;

using namespace bencode;

namespace Torrent {

    // ��������� ��� ������������� ������ ������ ��������
    struct TorrentFileInfo {
        unsigned long long length;                      // ������ ����� � ������
        vector<string> path;                            // ���� � ����� (��������, ["data.bin"])
    };

    // �������� ��������� ��� �������� ��������
    struct TorrentFile {

        string announce;                                // �������� ������
        vector<vector<string>> announceList;            // �������������� �������
        optional<string> createdBy;                     // ��� ������ (���� ����)
        optional<time_t> creationDate;                  // ���� �������� (UNIX Timestamp)

        struct Info {
            vector<TorrentFileInfo> files;              // ������ ������
            string name;                                // ��� ����� ��� �����
            unsigned long long pieceLength;             // ������ ����� ����� (� ������)
            string pieces;                              // ���� ���� ������ (�������� ������)
        } info;
    };

    struct ValueToField : public boost::static_visitor<> {
        TorrentFile& torrent;
        TorrentFile::Info& info;

        explicit ValueToField(TorrentFile& t)
            : torrent(t), info(t.info) {}

        void operator()(int value) const;

        void operator()(const string& value) const;

        void operator()(const ValueVector& values) const;

        void operator()(const ValueDictionary& dict) const;

        mutable string currentKey;
        mutable TorrentFileInfo currentFile;
    };

    // ������� ��� �������������� value � TorrentFile
    TorrentFile parseTorrentFile(const Value& data);
    Value toValue(const TorrentFile& torrent);
};

string readFile(const std::string& filePath);

#endif