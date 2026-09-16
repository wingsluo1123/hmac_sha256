export const HmacSha256HashBuffer: (key: ArrayBuffer, data: ArrayBuffer) => ArrayBuffer;
export const HmacSha256Hash: (key: string, data: string) => number[];
export const HmacSha256Hex: (key: string, data: string) => string;