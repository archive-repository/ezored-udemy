// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#import <Foundation/Foundation.h>


@protocol EZRFileHelperPlatformService

- (BOOL)createFile:(nonnull NSString *)path;

- (BOOL)createFileWithStringContent:(nonnull NSString *)path
                            content:(nonnull NSString *)content;

- (BOOL)createFileWithBinaryContent:(nonnull NSString *)path
                            content:(nonnull NSData *)content;

- (BOOL)createDir:(nonnull NSString *)path;

- (nonnull NSArray<NSString *> *)listFiles:(nonnull NSString *)path;

- (nonnull NSString *)getExtension:(nonnull NSString *)path;

- (nonnull NSString *)getFilename:(nonnull NSString *)path;

- (nonnull NSString *)getBasename:(nonnull NSString *)path;

- (nonnull NSString *)getFilenameFromUrl:(nonnull NSString *)url;

- (nonnull NSString *)getBasenameFromUrl:(nonnull NSString *)url;

- (BOOL)removeFile:(nonnull NSString *)path;

- (BOOL)removeDir:(nonnull NSString *)path;

- (BOOL)isDir:(nonnull NSString *)path;

- (BOOL)isFile:(nonnull NSString *)path;

- (int64_t)getFileSize:(nonnull NSString *)path;

- (BOOL)copyFile:(nonnull NSString *)from
              to:(nonnull NSString *)to;

- (BOOL)moveFile:(nonnull NSString *)from
              to:(nonnull NSString *)to;

- (nonnull NSString *)join:(nonnull NSString *)first
                    second:(nonnull NSString *)second;

- (nonnull NSString *)getFileContentAsString:(nonnull NSString *)path;

- (nonnull NSData *)getFileContentAsBinary:(nonnull NSString *)path;

- (nonnull NSString *)getHomeDir;

@end
