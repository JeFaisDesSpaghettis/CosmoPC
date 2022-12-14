#ifndef COSMODSK_HPP
#define COSMODSK_HPP

#include "cosmocore.hpp"
#include "cosmobus.hpp"

#include <cstring>

#include <fstream>
#include <vector>

namespace cosmocore
{
    const std::string DISK_PATH = "disk.bin";
    const std::size_t SECTOR_SIZE = 512;
    typedef enum _DISK_MODES
    {
        READ = 0,
        WRITE = 1,
    }DISK_MODES;

    class cosmodsk
    {
        private: u16i m_lba;
        private: u16i m_cache_index;
        private: std::size_t m_file_size;
        private: DISK_MODES m_mode;
        private: std::vector<u8i> m_cache;

        private: std::fstream m_file;
        private: std::shared_ptr<cosmobus>& m_bus;

        public: cosmodsk() = delete;
        public: cosmodsk(std::shared_ptr<cosmobus>& bus);
        public: ~cosmodsk();

        public: u16i set_mode(u16i mode);
        public: u16i set_lba(u16i lba);
        public: u16i do_it(u16i dummy);

        public: u16i request_read_write(u16i data_in);
        public: u16i get_sectors_count(u16i dummy);
    };
}

#endif /* COSMODSK_HPP */