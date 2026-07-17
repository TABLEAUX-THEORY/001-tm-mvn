# About
A minimal, software rendered modern visual novel development library.

# Design Goals
1. Intended to simplify development of modern visual novels as much as possible, as elegantly as possible.
2. While I would hope to eventually design a framework with a single piece of hardware in mind, this is not yet that framework (maybe 002-fw?). Instead, this framework should be optimized so that hardware communication is abstracted away from the product developers.

# `.img` file format

Custom raw image format used by `load_image`. Extension must be `.img`.

## Layout

| Offset | Size | Type | Description |
|--------|------|------|-------------|
| 0 | 4 | `uint32` LE | Width in pixels |
| 4 | 4 | `uint32` LE | Height in pixels |
| 8 | `width * height * 4` | pixels | Row-major pixel data |

Total size: `8 + width * height * 4` bytes.

## Pixel format

Each pixel is a little-endian `uint32` with layout **`0xRRGGBBAA`**:

| Bits | Channel |
|------|---------|
| 24–31 | R |
| 16–23 | G |
| 8–15 | B |
| 0–7 | A |

On disk (little-endian), that is byte order **`AA BB GG RR`**.

Pixels are stored top-to-bottom, left-to-right (row-major). No padding between rows.

## Example

32×32 image:

- Header: `20 00 00 00` `20 00 00 00` (width 32, height 32)
- Body: 1024 × 4 = 4096 bytes of pixels
- File size: 4104 bytes

Opaque red pixel as `uint32`: `0xFF0000FF` → bytes `FF 00 00 FF`.

## Notes

- Width and height must be non-zero.
- Alpha is straight (not premultiplied). `draw_pixel` blends with source alpha; fully transparent (`A = 0`) skips the write.
- Framebuffer / SDL texture use the same `0xRRGGBBAA` word layout (`SDL_PIXELFORMAT_RGBA8888`).
