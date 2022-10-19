#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// NORMAL                   0   xyz         1     NONE   float   xyz
// DIFFUSE                  0   xyz         2     NONE   float   xyz
// TRANSFORM                0   xyzw        3     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// COLOR                    0   xyzw        1     NONE   float   xyzw
//
vs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[7], immediateIndexed
dcl_input v0.xyzw
dcl_input v1.xyz
dcl_input v2.xyz
dcl_input v3.xyzw
dcl_output_siv o0.xyzw, position
dcl_output o1.xyzw
dcl_temps 2
mul r0.x, v0.y, v3.y
mad r0.x, v3.x, v0.x, -r0.x
dp2 r0.y, v3.yxyy, v0.xyxx
add r0.xy, r0.xyxx, v3.zwzz
mul r1.xyzw, r0.yyyy, cb0[1].xyzw
mad r0.xyzw, cb0[0].xyzw, r0.xxxx, r1.xyzw
mad r0.xyzw, cb0[2].xyzw, v0.zzzz, r0.xyzw
mad r0.xyzw, cb0[3].xyzw, v0.wwww, r0.xyzw
mov o0.xyzw, r0.xyzw
div r0.xyz, r0.xyzx, r0.wwww
add r0.xyz, -r0.xyzx, l(5.000000, 5.000000, 10.000000, 0.000000)
dp3 r0.w, r0.xyzx, r0.xyzx
rsq r0.w, r0.w
mul r0.xyz, r0.wwww, r0.xyzx
mul r0.w, v1.y, v3.y
mad r0.w, v3.x, v1.x, -r0.w
dp2 r1.x, v3.yxyy, v1.xyxx
mul r1.xyz, r1.xxxx, cb0[5].xyzx
mad r1.xyz, cb0[4].xyzx, r0.wwww, r1.xyzx
mad r1.xyz, cb0[6].xyzx, v1.zzzz, r1.xyzx
dp3 r0.w, r1.xyzx, r1.xyzx
rsq r0.w, r0.w
mul r1.xyz, r0.wwww, r1.xyzx
dp3 r0.x, r0.xyzx, r1.xyzx
add r0.x, r0.x, l(0.200000)
mul o1.xyz, r0.xxxx, v2.xyzx
mov o1.w, l(1.000000)
ret
// Approximately 0 instruction slots used
#endif

const BYTE g_vs_main[] =
{
     68,  88,  66,  67,  82,  90,
     22, 185,  41,  66, 113, 173,
     43,  53, 199,  35,  30,  50,
     78,   7,   1,   0,   0,   0,
    208,   4,   0,   0,   3,   0,
      0,   0,  44,   0,   0,   0,
    192,   0,   0,   0,  20,   1,
      0,   0,  73,  83,  71,  78,
    140,   0,   0,   0,   4,   0,
      0,   0,   8,   0,   0,   0,
    104,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      3,   0,   0,   0,   0,   0,
      0,   0,  15,  15,   0,   0,
    113,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      3,   0,   0,   0,   1,   0,
      0,   0,   7,   7,   0,   0,
    120,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      3,   0,   0,   0,   2,   0,
      0,   0,   7,   7,   0,   0,
    128,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      3,   0,   0,   0,   3,   0,
      0,   0,  15,  15,   0,   0,
     80,  79,  83,  73,  84,  73,
     79,  78,   0,  78,  79,  82,
     77,  65,  76,   0,  68,  73,
     70,  70,  85,  83,  69,   0,
     84,  82,  65,  78,  83,  70,
     79,  82,  77,   0, 171, 171,
     79,  83,  71,  78,  76,   0,
      0,   0,   2,   0,   0,   0,
      8,   0,   0,   0,  56,   0,
      0,   0,   0,   0,   0,   0,
      1,   0,   0,   0,   3,   0,
      0,   0,   0,   0,   0,   0,
     15,   0,   0,   0,  68,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   3,   0,
      0,   0,   1,   0,   0,   0,
     15,   0,   0,   0,  83,  86,
     95,  80,  79,  83,  73,  84,
     73,  79,  78,   0,  67,  79,
     76,  79,  82,   0, 171, 171,
     83,  72,  69,  88, 180,   3,
      0,   0,  80,   0,   1,   0,
    237,   0,   0,   0, 106,   8,
      0,   1,  89,   0,   0,   4,
     70, 142,  32,   0,   0,   0,
      0,   0,   7,   0,   0,   0,
     95,   0,   0,   3, 242,  16,
     16,   0,   0,   0,   0,   0,
     95,   0,   0,   3, 114,  16,
     16,   0,   1,   0,   0,   0,
     95,   0,   0,   3, 114,  16,
     16,   0,   2,   0,   0,   0,
     95,   0,   0,   3, 242,  16,
     16,   0,   3,   0,   0,   0,
    103,   0,   0,   4, 242,  32,
     16,   0,   0,   0,   0,   0,
      1,   0,   0,   0, 101,   0,
      0,   3, 242,  32,  16,   0,
      1,   0,   0,   0, 104,   0,
      0,   2,   2,   0,   0,   0,
     56,   0,   0,   7,  18,   0,
     16,   0,   0,   0,   0,   0,
     26,  16,  16,   0,   0,   0,
      0,   0,  26,  16,  16,   0,
      3,   0,   0,   0,  50,   0,
      0,  10,  18,   0,  16,   0,
      0,   0,   0,   0,  10,  16,
     16,   0,   3,   0,   0,   0,
     10,  16,  16,   0,   0,   0,
      0,   0,  10,   0,  16, 128,
     65,   0,   0,   0,   0,   0,
      0,   0,  15,   0,   0,   7,
     34,   0,  16,   0,   0,   0,
      0,   0,  22,  21,  16,   0,
      3,   0,   0,   0,  70,  16,
     16,   0,   0,   0,   0,   0,
      0,   0,   0,   7,  50,   0,
     16,   0,   0,   0,   0,   0,
     70,   0,  16,   0,   0,   0,
      0,   0, 230,  26,  16,   0,
      3,   0,   0,   0,  56,   0,
      0,   8, 242,   0,  16,   0,
      1,   0,   0,   0,  86,   5,
     16,   0,   0,   0,   0,   0,
     70, 142,  32,   0,   0,   0,
      0,   0,   1,   0,   0,   0,
     50,   0,   0,  10, 242,   0,
     16,   0,   0,   0,   0,   0,
     70, 142,  32,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      6,   0,  16,   0,   0,   0,
      0,   0,  70,  14,  16,   0,
      1,   0,   0,   0,  50,   0,
      0,  10, 242,   0,  16,   0,
      0,   0,   0,   0,  70, 142,
     32,   0,   0,   0,   0,   0,
      2,   0,   0,   0, 166,  26,
     16,   0,   0,   0,   0,   0,
     70,  14,  16,   0,   0,   0,
      0,   0,  50,   0,   0,  10,
    242,   0,  16,   0,   0,   0,
      0,   0,  70, 142,  32,   0,
      0,   0,   0,   0,   3,   0,
      0,   0, 246,  31,  16,   0,
      0,   0,   0,   0,  70,  14,
     16,   0,   0,   0,   0,   0,
     54,   0,   0,   5, 242,  32,
     16,   0,   0,   0,   0,   0,
     70,  14,  16,   0,   0,   0,
      0,   0,  14,   0,   0,   7,
    114,   0,  16,   0,   0,   0,
      0,   0,  70,   2,  16,   0,
      0,   0,   0,   0, 246,  15,
     16,   0,   0,   0,   0,   0,
      0,   0,   0,  11, 114,   0,
     16,   0,   0,   0,   0,   0,
     70,   2,  16, 128,  65,   0,
      0,   0,   0,   0,   0,   0,
      2,  64,   0,   0,   0,   0,
    160,  64,   0,   0, 160,  64,
      0,   0,  32,  65,   0,   0,
      0,   0,  16,   0,   0,   7,
    130,   0,  16,   0,   0,   0,
      0,   0,  70,   2,  16,   0,
      0,   0,   0,   0,  70,   2,
     16,   0,   0,   0,   0,   0,
     68,   0,   0,   5, 130,   0,
     16,   0,   0,   0,   0,   0,
     58,   0,  16,   0,   0,   0,
      0,   0,  56,   0,   0,   7,
    114,   0,  16,   0,   0,   0,
      0,   0, 246,  15,  16,   0,
      0,   0,   0,   0,  70,   2,
     16,   0,   0,   0,   0,   0,
     56,   0,   0,   7, 130,   0,
     16,   0,   0,   0,   0,   0,
     26,  16,  16,   0,   1,   0,
      0,   0,  26,  16,  16,   0,
      3,   0,   0,   0,  50,   0,
      0,  10, 130,   0,  16,   0,
      0,   0,   0,   0,  10,  16,
     16,   0,   3,   0,   0,   0,
     10,  16,  16,   0,   1,   0,
      0,   0,  58,   0,  16, 128,
     65,   0,   0,   0,   0,   0,
      0,   0,  15,   0,   0,   7,
     18,   0,  16,   0,   1,   0,
      0,   0,  22,  21,  16,   0,
      3,   0,   0,   0,  70,  16,
     16,   0,   1,   0,   0,   0,
     56,   0,   0,   8, 114,   0,
     16,   0,   1,   0,   0,   0,
      6,   0,  16,   0,   1,   0,
      0,   0,  70, 130,  32,   0,
      0,   0,   0,   0,   5,   0,
      0,   0,  50,   0,   0,  10,
    114,   0,  16,   0,   1,   0,
      0,   0,  70, 130,  32,   0,
      0,   0,   0,   0,   4,   0,
      0,   0, 246,  15,  16,   0,
      0,   0,   0,   0,  70,   2,
     16,   0,   1,   0,   0,   0,
     50,   0,   0,  10, 114,   0,
     16,   0,   1,   0,   0,   0,
     70, 130,  32,   0,   0,   0,
      0,   0,   6,   0,   0,   0,
    166,  26,  16,   0,   1,   0,
      0,   0,  70,   2,  16,   0,
      1,   0,   0,   0,  16,   0,
      0,   7, 130,   0,  16,   0,
      0,   0,   0,   0,  70,   2,
     16,   0,   1,   0,   0,   0,
     70,   2,  16,   0,   1,   0,
      0,   0,  68,   0,   0,   5,
    130,   0,  16,   0,   0,   0,
      0,   0,  58,   0,  16,   0,
      0,   0,   0,   0,  56,   0,
      0,   7, 114,   0,  16,   0,
      1,   0,   0,   0, 246,  15,
     16,   0,   0,   0,   0,   0,
     70,   2,  16,   0,   1,   0,
      0,   0,  16,   0,   0,   7,
     18,   0,  16,   0,   0,   0,
      0,   0,  70,   2,  16,   0,
      0,   0,   0,   0,  70,   2,
     16,   0,   1,   0,   0,   0,
      0,   0,   0,   7,  18,   0,
     16,   0,   0,   0,   0,   0,
     10,   0,  16,   0,   0,   0,
      0,   0,   1,  64,   0,   0,
    205, 204,  76,  62,  56,   0,
      0,   7, 114,  32,  16,   0,
      1,   0,   0,   0,   6,   0,
     16,   0,   0,   0,   0,   0,
     70,  18,  16,   0,   2,   0,
      0,   0,  54,   0,   0,   5,
    130,  32,  16,   0,   1,   0,
      0,   0,   1,  64,   0,   0,
      0,   0, 128,  63,  62,   0,
      0,   1
};
