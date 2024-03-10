# Panasonic Raw (rw2) file format

Panasonic cameras can create RAW files for Photos with the .RAW or .RW2 extension. Which of RW2 is RW the latest.

## mime type

image/x-panasonic-rw
image/x-panasonic-rw2

## Infos

TIFF but with a different version in the magic: IIU\x00\x08\x00\x00\x00. Also the tags are uncommon. The CFA is in the mainIFD that also reference an Exif IFD.

Old RAW files don’t have a preview. Newer one (some RAW and all RW2) have a complete JPEG with Exif embedded.

The RAW data is compressed (proprietary). The CFA bayer layout is BGGR.

