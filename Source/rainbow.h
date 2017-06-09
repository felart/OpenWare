/* rainbow table 1024 values */
const uint32_t rainbow[1024] = { 0x2530034f, 0x2510034d, 0x24f0034b, 0x24d00349, 0x24c00347, 0x24a00345, 0x24800343, 0x24600341, 0x2450033f, 0x2430033d, 0x2410033b, 0x23f00339, 0x23e00337, 0x23c00336, 0x23a00334, 0x23900332, 0x23700330, 0x2350032e, 0x2330032c, 0x2320032a, 0x23000328, 0x22e00326, 0x22c00324, 0x22b00322, 0x22900320, 0x2270031f, 0x2260031d, 0x2240031b, 0x22200319, 0x22000317, 0x21f00315, 0x21d00313, 0x21b00311, 0x2190030f, 0x2180030d, 0x2160030b, 0x21400309, 0x21300308, 0x21100306, 0x20f00304, 0x20d00302, 0x20c00300, 0x20a002fe, 0x208002fc, 0x206002fa, 0x205002f8, 0x203002f6, 0x201002f4, 0x200002f2, 0x1fe002f1, 0x1fc002ef, 0x1fa002ed, 0x1f9002eb, 0x1f7002e9, 0x1f5002e7, 0x1f3002e5, 0x1f2002e3, 0x1f0002e1, 0x1ee002df, 0x1ed002dd, 0x1eb002db, 0x1e9002da, 0x1e7002d8, 0x1e6002d6, 0x1e4002d4, 0x1e2002d2, 0x1e0002d0, 0x1df002ce, 0x1dd002cc, 0x1db002ca, 0x1da002c8, 0x1d8002c6, 0x1d6002c4, 0x1d4002c3, 0x1d3002c1, 0x1d1002bf, 0x1cf002bd, 0x1cd002bb, 0x1cc002b9, 0x1ca002b7, 0x1c8002b5, 0x1c7002b3, 0x1c5002b1, 0x1c3002af, 0x1c1002ad, 0x1c0002ac, 0x1be002aa, 0x1bc002a8, 0x1ba002a6, 0x1b9002a4, 0x1b7002a2, 0x1b5002a0, 0x1b40029e, 0x1b20029c, 0x1b00029a, 0x1ae00298, 0x1ad00296, 0x1ab00295, 0x1a900293, 0x1a700291, 0x1a60028f, 0x1a40028d, 0x1a20028b, 0x1a100289, 0x19f00287, 0x19d00285, 0x19b00283, 0x19a00281, 0x1980027f, 0x1960027e, 0x1940027c, 0x1930027a, 0x19100278, 0x18f00276, 0x18e00274, 0x18c00272, 0x18a00270, 0x1880026e, 0x1870026c, 0x1850026a, 0x18300268, 0x18100267, 0x18000265, 0x17e00263, 0x17c00261, 0x17b0025f, 0x1790025d, 0x1770025b, 0x17500259, 0x17400257, 0x17200255, 0x17000253, 0x16e00251, 0x16d00250, 0x16b0024e, 0x1690024c, 0x1680024a, 0x16600248, 0x16400246, 0x16200244, 0x16100242, 0x15f00240, 0x15d0023e, 0x15b0023c, 0x15a0023a, 0x15800239, 0x15600237, 0x15500235, 0x15300233, 0x15100231, 0x14f0022f, 0x14e0022d, 0x14c0022b, 0x14a00229, 0x14800227, 0x14700225, 0x14500223, 0x14300222, 0x14200220, 0x1400021e, 0x13e0021c, 0x13c0021a, 0x13b00218, 0x13900216, 0x13700214, 0x13500212, 0x13400210, 0x1320020e, 0x1300020c, 0x12f0020b, 0x12f0020b, 0x12d0020d, 0x12b00210, 0x12900213, 0x12700216, 0x12600219, 0x1240021c, 0x1220021f, 0x12000222, 0x11e00225, 0x11d00228, 0x11b0022b, 0x1190022e, 0x11700231, 0x11500234, 0x11400237, 0x1120023a, 0x1100023d, 0x10e00240, 0x10c00243, 0x10b00246, 0x10900249, 0x1070024c, 0x1050024f, 0x10300252, 0x10200254, 0x10000257, 0xfe0025a, 0xfc0025d, 0xfb00260, 0xf900263, 0xf700266, 0xf500269, 0xf30026c, 0xf20026f, 0xf000272, 0xee00275, 0xec00278, 0xea0027b, 0xe90027e, 0xe700281, 0xe500284, 0xe300287, 0xe10028a, 0xe00028d, 0xde00290, 0xdc00293, 0xda00296, 0xd800299, 0xd70029b, 0xd50029e, 0xd3002a1, 0xd1002a4, 0xcf002a7, 0xce002aa, 0xcc002ad, 0xca002b0, 0xc8002b3, 0xc7002b6, 0xc5002b9, 0xc3002bc, 0xc1002bf, 0xbf002c2, 0xbe002c5, 0xbc002c8, 0xba002cb, 0xb8002ce, 0xb6002d1, 0xb5002d4, 0xb3002d7, 0xb1002da, 0xaf002dd, 0xad002e0, 0xac002e2, 0xaa002e5, 0xa8002e8, 0xa6002eb, 0xa4002ee, 0xa3002f1, 0xa1002f4, 0x9f002f7, 0x9d002fa, 0x9b002fd, 0x9a00300, 0x9800303, 0x9600306, 0x9400309, 0x930030c, 0x910030f, 0x8f00312, 0x8d00315, 0x8b00318, 0x8a0031b, 0x880031e, 0x8600321, 0x8400324, 0x8200327, 0x8100329, 0x7f0032c, 0x7d0032f, 0x7b00332, 0x7900335, 0x7800338, 0x760033b, 0x740033e, 0x7200341, 0x7000344, 0x6f00347, 0x6d0034a, 0x6b0034d, 0x6900350, 0x6700353, 0x6600356, 0x6400359, 0x620035c, 0x600035f, 0x5f00362, 0x5d00365, 0x5b00368, 0x590036b, 0x570036e, 0x5600370, 0x5400373, 0x5200376, 0x5000379, 0x4e0037c, 0x4d0037f, 0x4b00382, 0x4900385, 0x4700388, 0x450038b, 0x440038e, 0x4200391, 0x4000394, 0x3e00397, 0x3c0039a, 0x3b0039d, 0x39003a0, 0x37003a3, 0x35003a6, 0x33003a9, 0x32003ac, 0x30003af, 0x2e003b2, 0x2c003b5, 0x2b003b7, 0x29003ba, 0x27003bd, 0x25003c0, 0x23003c3, 0x22003c6, 0x20003c9, 0x1e003cc, 0x1c003cf, 0x1a003d2, 0x19003d5, 0x17003d8, 0x15003db, 0x13003de, 0x11003e1, 0x10003e4, 0xe003e7, 0xc003ea, 0xa003ed, 0x8003f0, 0x7003f3, 0x5003f6, 0x3003f9, 0x1003fc, 0x0003ff, 0x0003ff, 0x001bf8, 0x0033f2, 0x004bec, 0x0063e6, 0x007be0, 0x0093da, 0x00abd4, 0x00c3ce, 0x00dbc8, 0x00f3c2, 0x010bbc, 0x0123b6, 0x013bb0, 0x0153aa, 0x016ba4, 0x01839e, 0x019b98, 0x01b392, 0x01cf8b, 0x01e785, 0x01ff7f, 0x021779, 0x022f73, 0x02476d, 0x025f67, 0x027761, 0x028f5b, 0x02a755, 0x02bf4f, 0x02d749, 0x02ef43, 0x03073d, 0x031f37, 0x033731, 0x034f2b, 0x036725, 0x037f1f, 0x039b18, 0x03b312, 0x03cb0c, 0x03e306, 0x03fb00, 0x0412fa, 0x042af4, 0x0442ee, 0x045ae8, 0x0472e2, 0x048adc, 0x04a2d6, 0x04bad0, 0x04d2ca, 0x04eac4, 0x0502be, 0x051ab8, 0x0532b2, 0x054aac, 0x0566a5, 0x057e9f, 0x059699, 0x05ae93, 0x05c68d, 0x05de87, 0x05f681, 0x060e7b, 0x062675, 0x063e6f, 0x065669, 0x066e63, 0x06865d, 0x069e57, 0x06b651, 0x06ce4b, 0x06e645, 0x06fe3f, 0x071639, 0x073232, 0x074a2c, 0x076226, 0x077a20, 0x07921a, 0x07aa14, 0x07c20e, 0x07da08, 0x07f202, 0x0809fc, 0x0821f6, 0x0839f0, 0x0851ea, 0x0869e4, 0x0881de, 0x0899d8, 0x08b1d2, 0x08c9cc, 0x08e5c5, 0x08fdbf, 0x0915b9, 0x092db3, 0x0945ad, 0x095da7, 0x0975a1, 0x098d9b, 0x09a595, 0x09bd8f, 0x09d589, 0x09ed83, 0x0a057d, 0x0a1d77, 0x0a3571, 0x0a4d6b, 0x0a6565, 0x0a7d5f, 0x0a9559, 0x0ab152, 0x0ac94c, 0x0ae146, 0x0af940, 0x0b113a, 0x0b2934, 0x0b412e, 0x0b5928, 0x0b7122, 0x0b891c, 0x0ba116, 0x0bb910, 0x0bd10a, 0x0be904, 0x0c00fe, 0x0c18f8, 0x0c30f2, 0x0c48ec, 0x0c60e6, 0x0c7cdf, 0x0c94d9, 0x0cacd3, 0x0cc4cd, 0x0cdcc7, 0x0cf4c1, 0x0d0cbb, 0x0d24b5, 0x0d3caf, 0x0d54a9, 0x0d6ca3, 0x0d849d, 0x0d9c97, 0x0db491, 0x0dcc8b, 0x0de485, 0x0dfc7f, 0x0e1479, 0x0e2c73, 0x0e486c, 0x0e6066, 0x0e7860, 0x0e905a, 0x0ea854, 0x0ec04e, 0x0ed848, 0x0ef042, 0x0f083c, 0x0f2036, 0x0f3830, 0x0f502a, 0x0f6824, 0x0f801e, 0x0f9818, 0x0fb012, 0x0fc80c, 0x0fe006, 0x0ffc00, 0x0ffc00, 0x6ffc00, 0xcff800, 0x12ffc00, 0x18ff800, 0x1effc00, 0x24ff800, 0x2affc00, 0x30ff800, 0x36ffc00, 0x3cff800, 0x42ffc00, 0x48ff800, 0x4effc00, 0x54ff800, 0x5affc00, 0x60ffc00, 0x66ffc00, 0x6cffc00, 0x73ff800, 0x79ffc00, 0x7fff800, 0x85ffc00, 0x8bff800, 0x91ffc00, 0x97ff800, 0x9dffc00, 0xa3ff800, 0xa9ffc00, 0xafff800, 0xb5ffc00, 0xbbffc00, 0xc1ffc00, 0xc7ffc00, 0xcdffc00, 0xd3ffc00, 0xd9ff800, 0xdfffc00, 0xe6ff800, 0xecffc00, 0xf2ff800, 0xf8ffc00, 0xfeff800, 0x104ffc00, 0x10aff800, 0x110ffc00, 0x116ff800, 0x11cffc00, 0x122ffc00, 0x128ffc00, 0x12effc00, 0x134ffc00, 0x13affc00, 0x140ffc00, 0x146ffc00, 0x14cff800, 0x152ffc00, 0x159ff800, 0x15fffc00, 0x165ff800, 0x16bffc00, 0x171ff800, 0x177ffc00, 0x17dffc00, 0x183ffc00, 0x189ffc00, 0x18fffc00, 0x195ffc00, 0x19bffc00, 0x1a1ffc00, 0x1a7ff800, 0x1adffc00, 0x1b3ff800, 0x1b9ffc00, 0x1bfff800, 0x1c5ffc00, 0x1ccff800, 0x1d2ffc00, 0x1d8ffc00, 0x1deffc00, 0x1e4ffc00, 0x1eaffc00, 0x1f0ffc00, 0x1f6ffc00, 0x1fcffc00, 0x202ffc00, 0x208ffc00, 0x20effc00, 0x214ffc00, 0x21affc00, 0x220ffc00, 0x226ffc00, 0x22cffc00, 0x232ff800, 0x239ffc00, 0x23fff800, 0x245ffc00, 0x24bff800, 0x251ffc00, 0x257ff800, 0x25dffc00, 0x263ffc00, 0x269ffc00, 0x26fffc00, 0x275ffc00, 0x27bffc00, 0x281ffc00, 0x287ffc00, 0x28dff800, 0x293ffc00, 0x299ff800, 0x29fffc00, 0x2a5ff800, 0x2acffc00, 0x2b2ff800, 0x2b8ffc00, 0x2beffc00, 0x2c4ffc00, 0x2caffc00, 0x2d0ffc00, 0x2d6ffc00, 0x2dcffc00, 0x2e2ffc00, 0x2e8ff800, 0x2eeffc00, 0x2f4ff800, 0x2faffc00, 0x300ff800, 0x306ffc00, 0x30cff800, 0x312ffc00, 0x318ff800, 0x31fffc00, 0x325ff800, 0x32bffc00, 0x331ffc00, 0x337ffc00, 0x33dffc00, 0x343ffc00, 0x349ffc00, 0x34fff800, 0x355ffc00, 0x35bff800, 0x361ffc00, 0x367ff800, 0x36dffc00, 0x373ff800, 0x379ffc00, 0x37fff800, 0x385ffc00, 0x38bff800, 0x392ffc00, 0x398ffc00, 0x39effc00, 0x3a4ffc00, 0x3aaff800, 0x3b0ffc00, 0x3b6ff800, 0x3bcffc00, 0x3c2ff800, 0x3c8ffc00, 0x3ceff800, 0x3d4ffc00, 0x3daff800, 0x3e0ffc00, 0x3e6ff800, 0x3ecffc00, 0x3f2ff800, 0x3f8ffc00, 0x3ffffc00, 0x3ffffc00, 0x3ffff800, 0x3feff800, 0x3ffff800, 0x3feff800, 0x3ffff800, 0x3feff400, 0x3ffff400, 0x3feff400, 0x3ffff400, 0x3feff400, 0x3ffff000, 0x3feff000, 0x3ffff000, 0x3feff000, 0x3ffff000, 0x3fffec00, 0x3fffec00, 0x3fffec00, 0x3fefec00, 0x3fffec00, 0x3fefec00, 0x3fffe800, 0x3fefe800, 0x3fffe800, 0x3fefe800, 0x3fffe800, 0x3fefe400, 0x3fffe400, 0x3fefe400, 0x3fffe400, 0x3fffe400, 0x3fffe000, 0x3fffe000, 0x3fffe000, 0x3fffe000, 0x3fefe000, 0x3fffdc00, 0x3fefdc00, 0x3fffdc00, 0x3fefdc00, 0x3fffdc00, 0x3fefdc00, 0x3fffd800, 0x3fefd800, 0x3fffd800, 0x3fefd800, 0x3fffd800, 0x3fffd400, 0x3fffd400, 0x3fffd400, 0x3fffd400, 0x3fffd400, 0x3fffd000, 0x3fffd000, 0x3fefd000, 0x3fffd000, 0x3fefd000, 0x3fffd000, 0x3fefcc00, 0x3fffcc00, 0x3fefcc00, 0x3fffcc00, 0x3fffcc00, 0x3fffc800, 0x3fffc800, 0x3fffc800, 0x3fffc800, 0x3fffc800, 0x3fffc400, 0x3fefc400, 0x3fffc400, 0x3fefc400, 0x3fffc400, 0x3fefc000, 0x3fffc000, 0x3fefc000, 0x3fffc000, 0x3fffc000, 0x3fffc000, 0x3fffbc00, 0x3fffbc00, 0x3fffbc00, 0x3fffbc00, 0x3fffbc00, 0x3fffb800, 0x3fffb800, 0x3fffb800, 0x3fffb800, 0x3fffb800, 0x3fffb400, 0x3fffb400, 0x3fffb400, 0x3fefb400, 0x3fffb400, 0x3fefb400, 0x3fffb000, 0x3fefb000, 0x3fffb000, 0x3fefb000, 0x3fffb000, 0x3fffac00, 0x3fffac00, 0x3fffac00, 0x3fffac00, 0x3fffac00, 0x3fffa800, 0x3fffa800, 0x3fefa800, 0x3fffa800, 0x3fefa800, 0x3fffa400, 0x3fefa400, 0x3fffa400, 0x3fefa400, 0x3fffa400, 0x3fffa400, 0x3fffa000, 0x3fffa000, 0x3fffa000, 0x3fffa000, 0x3fffa000, 0x3fff9c00, 0x3fef9c00, 0x3fff9c00, 0x3fef9c00, 0x3fff9c00, 0x3fef9800, 0x3fff9800, 0x3fef9800, 0x3fff9800, 0x3fef9800, 0x3fff9800, 0x3fef9400, 0x3fff9400, 0x3fff9400, 0x3fff9400, 0x3fff9400, 0x3fff9000, 0x3fff9000, 0x3fef9000, 0x3fff9000, 0x3fef9000, 0x3fff8c00, 0x3fef8c00, 0x3fff8c00, 0x3fef8c00, 0x3fff8c00, 0x3fef8800, 0x3fff8800, 0x3fef8800, 0x3fff8800, 0x3fff8800, 0x3fff8800, 0x3fff8400, 0x3fef8400, 0x3fff8400, 0x3fef8400, 0x3fff8400, 0x3fef8000, 0x3fff8000, 0x3fef8000, 0x3fff8000, 0x3fef8000, 0x3fff7c00, 0x3fef7c00, 0x3fff7c00, 0x3fef7c00, 0x3fff7c00, 0x3fff7c00, 0x3fff7c00, 0x3fff6400, 0x3fef4c00, 0x3fff3400, 0x3fef1c00, 0x3fff0400, 0x3feeec00, 0x3ffed400, 0x3feec000, 0x3ffea800, 0x3fee9000, 0x3ffe7800, 0x3fee6000, 0x3ffe4800, 0x3fee3000, 0x3ffe1c00, 0x3ffe0400, 0x3ffdec00, 0x3ffdd400, 0x3fedbc00, 0x3ffda400, 0x3fed8c00, 0x3ffd7400, 0x3fed6000, 0x3ffd4800, 0x3fed3000, 0x3ffd1800, 0x3fed0000, 0x3ffce800, 0x3fecd000, 0x3ffcbc00, 0x3ffca400, 0x3ffc8c00, 0x3ffc7400, 0x3ffc5c00, 0x3ffc4400, 0x3fec2c00, 0x3ffc1800, 0x3fec0000, 0x3ffbe800, 0x3febd000, 0x3ffbb800, 0x3feba000, 0x3ffb8800, 0x3feb7000, 0x3ffb5c00, 0x3feb4400, 0x3ffb2c00, 0x3ffb1400, 0x3ffafc00, 0x3ffae400, 0x3ffacc00, 0x3ffab800, 0x3ffaa000, 0x3ffa8800, 0x3fea7000, 0x3ffa5800, 0x3fea4000, 0x3ffa2800, 0x3fea1400, 0x3ff9fc00, 0x3fe9e400, 0x3ff9cc00, 0x3ff9b400, 0x3ff99c00, 0x3ff98400, 0x3ff96c00, 0x3ff95800, 0x3ff94000, 0x3ff92800, 0x3fe91000, 0x3ff8f800, 0x3fe8e000, 0x3ff8c800, 0x3fe8b400, 0x3ff89c00, 0x3fe88400, 0x3ff86c00, 0x3ff85400, 0x3ff83c00, 0x3ff82400, 0x3ff81000, 0x3ff7f800, 0x3ff7e000, 0x3ff7c800, 0x3ff7b000, 0x3ff79800, 0x3ff78000, 0x3ff76800, 0x3ff75400, 0x3ff73c00, 0x3ff72400, 0x3ff70c00, 0x3fe6f400, 0x3ff6dc00, 0x3fe6c400, 0x3ff6b000, 0x3fe69800, 0x3ff68000, 0x3fe66800, 0x3ff65000, 0x3ff63800, 0x3ff62000, 0x3ff60c00, 0x3ff5f400, 0x3ff5dc00, 0x3ff5c400, 0x3ff5ac00, 0x3fe59400, 0x3ff57c00, 0x3fe56400, 0x3ff55000, 0x3fe53800, 0x3ff52000, 0x3fe50800, 0x3ff4f000, 0x3ff4d800, 0x3ff4c000, 0x3ff4ac00, 0x3ff49400, 0x3ff47c00, 0x3ff46400, 0x3ff44c00, 0x3fe43400, 0x3ff41c00, 0x3fe40800, 0x3ff3f000, 0x3fe3d800, 0x3ff3c000, 0x3fe3a800, 0x3ff39000, 0x3fe37800, 0x3ff36000, 0x3fe34c00, 0x3ff33400, 0x3ff31c00, 0x3ff30400, 0x3ff2ec00, 0x3ff2d400, 0x3ff2bc00, 0x3fe2a800, 0x3ff29000, 0x3fe27800, 0x3ff26000, 0x3fe24800, 0x3ff23000, 0x3fe21800, 0x3ff20400, 0x3fe1ec00, 0x3ff1d400, 0x3fe1bc00, 0x3ff1a400, 0x3ff18c00, 0x3ff17400, 0x3ff15c00, 0x3fe14800, 0x3ff13000, 0x3fe11800, 0x3ff10000, 0x3fe0e800, 0x3ff0d000, 0x3fe0b800, 0x3ff0a400, 0x3fe08c00, 0x3ff07400, 0x3fe05c00, 0x3ff04400, 0x3fe02c00, 0x3ff01400, 0x3ff00000, 0x3ff00000, 0x3ff00000, 0x3ff00000, 0x3ff00000,  };
