
#pragma once

#pragma pack (push, 8)

typedef enum {
    PATH_NOERR = 0,
    PATH_INVALID,
    PATH_BADOP,
    PATH_REFUSED,
    PATH_ERR
} PathErr;

typedef enum {
    NO_PATH = 0,
    NEW_PATH,
    WC_PATH,
    FILE_PATH,
    DIR_PATH,
    DEV_PATH,
} path_type;

enum path_category {
    DRIVE_TYPE,
    UNC_TYPE,
    ROOT_TYPE,
    RELATIVE_TYPE
};

enum FS_TYPE {
    NOFS,
    UKFS,
    NTFS,
    FAT,
    VFAT,
    HPFS,
    CDFS,
    HFS,
    UFS
};

enum path_status{
    PATH_NOTEXISTS = 0x00,
    PATH_EXISTS    = 0x01,
    PATH_READ      = 0x02,
    PATH_READWRITE = 0x04
};

#pragma pack (pop)

