import os
import tarfile
import zipfile
from os import path
from enum import Enum


def is_string(obj):
    return isinstance(obj, str)


class ArchiveType(Enum):
    ZIP = 0
    TAR = 1


ARCHIVE_TYPES = {
    'docx': ArchiveType.ZIP,
    'egg': ArchiveType.ZIP,
    'jar': ArchiveType.ZIP,
    'odg': ArchiveType.ZIP,
    'odp': ArchiveType.ZIP,
    'ods': ArchiveType.ZIP,
    'odt': ArchiveType.ZIP,
    'pptx': ArchiveType.ZIP,
    'tar': ArchiveType.TAR,
    'tar.bz2': ArchiveType.TAR,
    'tar.gz': ArchiveType.TAR,
    'tgz': ArchiveType.TAR,
    'tz2': ArchiveType.TAR,
    'xlsx': ArchiveType.ZIP,
    'zip': ArchiveType.ZIP,
}


class UnsupportedArchiveType(Exception):
    pass


class ArchiveHandler(object):
    
    def __init__(self, next_handler=None):
        self.next_handler = next_handler
    
    def extract(self, archive, unpacked_path):
        if self.next_handler is not None:
            self.next_handler.extract(archive, unpacked_path)
            
    def write(self, archive, file_to_write):
        if self.next_handler is not None:
            self.next_handler.extract(archive, file_to_write)


class File(object):
    def __init__(self, file_path):
        if is_string(file_path):
            self.file = file_path
        else:
            raise TypeError("File name or path must be a string")
    
    def is_existed(self):
        return path.exists(self.get_abs_path())
    
    def get_format(self):
        return self.get_name().split(".", maxsplit=1)[1]
    
    def get_name(self):
        return path.basename(self.file)
    
    def get_norm_path(self):
        return path.normpath(self.file)
    
    def get_abs_path(self):
        return path.abspath(self.file)
    
    def get_directory(self):
        return path.dirname(self.file)


def check_file_for_existence(file):
    if not file.is_existed():
        raise FileNotFoundError(f"{file.get_abs_path()} doesn't exists")


def check_file_for_not_existence(file):
    try:
        check_file_for_existence(file)
        raise FileExistsError(f"{file.get_abs_path()} already exists")
    except FileNotFoundError:
        pass


class Archive(object):

    def __init__(self, file):
        self.file = file
        check_file_for_existence(file)
        self.get_archive_type()
        self.archive_path = self.file.get_norm_path()
        self.archive_name = self.file.get_name()
        self.__build_chain__()

    def __build_chain__(self):
        self.chain = ArchiveZIP(ArchiveTAR())

    def get_archive_type(self):
        format = self.file.get_format()
        self.archive_type = ARCHIVE_TYPES.get(format)
        if not self.archive_type:
            raise UnsupportedArchiveType(f"{format} isn't supported")
        return self.archive_type

    def extract(self, unpacked_path=''):
        unpacked_path = File(unpacked_path)
        try:
            check_file_for_existence(unpacked_path)
        except FileNotFoundError:
            print(f"Path {unpacked_path.get_abs_path()} doesn't exists")
            os.makedirs(unpacked_path.get_abs_path())
            print(f"Path {unpacked_path} was created")
        self.chain.extract(self, unpacked_path)
        
    def write(self, file_to_write):
        file_to_write = File(file_to_write)
        try:
            check_file_for_existence(file_to_write)
            self.chain.extract(self, file_to_write)
        except FileNotFoundError:
            print(f"File {file_to_write.get_name()} doesn't exists")


class ArchiveZIP(ArchiveHandler):
    def extract(self, archive, unpacked_path):
        if archive.get_archive_type() == ArchiveType.ZIP:
            zip_file = zipfile.ZipFile(archive.file.get_norm_path(), "r")
            for member in zip_file.infolist():
                try:
                    check_file_for_not_existence(File(member.filename))
                    zip_file.extract(member, unpacked_path.get_abs_path())
                    print(f"Extracted {member.filename} to {unpacked_path.get_abs_path()}")
                except FileExistsError:
                    print(f"File {member.filename} already exists in {unpacked_path.get_abs_path()}")
            zip_file.close()
        else:
            super(ArchiveZIP, self).extract(archive, unpacked_path)

    def write(self, archive, file_to_write):
        if archive.get_archive_type() == ArchiveType.ZIP:
            zip_file = zipfile.ZipFile(archive.file.get_norm_path(), "w")
            if file_to_write.get_name() in zip_file.namelist():
                raise FileExistsError(f"{file_to_write.get_name()} already exists in {archive.file.get_name()}")
            zip_file.write(file_to_write.get_abs_path())
            print(f"{file_to_write.get_name()} has been written to {archive.file.get_name()}")
            zip_file.close()
        else:
            super(ArchiveZIP, self).write(archive, file_to_write)


class ArchiveTAR(ArchiveHandler):
    def extract(self, archive, unpacked_path):
        if archive.get_archive_type() == ArchiveType.TAR:
            tar_file = tarfile.TarFile(archive.file.get_norm_path(), mode="r")
            for member in tar_file.getmembers():
                try:
                    check_file_for_not_existence(File(member.filename))
                    tar_file.extract(member, unpacked_path.get_abs_path())
                    print(f"Extracted {member.filename} to {unpacked_path.get_abs_path()}")
                except FileExistsError:
                    print(f"File {member.filename} already exists in {unpacked_path.get_abs_path()}")
            tar_file.close()
        else:
            super(ArchiveTAR, self).extract(archive, unpacked_path)
            
    def write(self, archive, file_to_write):
        if archive.get_archive_type() == ArchiveType.TAR:
            tar_file = tarfile.TarFile(archive.file.get_norm_path(), mode="w")
            if file_to_write.get_name() in tar_file.getnames():
                raise FileExistsError(f"{file_to_write.get_name()} already exists in {archive.file.get_name()}")
            tar_file.add(file_to_write)
            print(f"{file_to_write.get_name()} has been written to {archive.file.get_name()}")
            tar_file.close()
        else:
            super(ArchiveTAR, self).write(archive, file_to_write)
        
        
def main():
    try:
        archive_zip = Archive(File("C:\\Users\\home\\Downloads\\test.zip"))
        archive_zip.extract()
        archive_zip.extract("C:\\Users\\home\\Downloads")
        archive_tar = Archive(File("C:\\Users\\home\\Downloads\\test.tar.gz"))
        archive_tar.write("C:\\Users\\home\\Downloads\\text2.txt")
        archive_tar.extract()
    except Exception as error:
        print(error)
        



main()