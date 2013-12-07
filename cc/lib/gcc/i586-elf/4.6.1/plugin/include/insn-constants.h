/* Generated automatically by the program `genconstants'
   from the machine description file `md'.  */

#ifndef GCC_INSN_CONSTANTS_H
#define GCC_INSN_CONSTANTS_H

#define XMM9_REG 46
#define R13_REG 42
#define XMM14_REG 51
#define PCOM_TRUE 1
#define PPERM_SRC 0x00
#define PPERM_ZERO 0x80
#define MM7_REG 36
#define XMM6_REG 27
#define ST3_REG 11
#define R10_REG 39
#define XMM11_REG 48
#define MM4_REG 33
#define ST7_REG 15
#define COM_FALSE_P 3
#define XMM3_REG 24
#define ST0_REG 8
#define COM_FALSE_S 2
#define SP_REG 7
#define AX_REG 0
#define ST6_REG 14
#define MM3_REG 32
#define XMM0_REG 21
#define XMM8_REG 45
#define ST5_REG 13
#define R12_REG 41
#define XMM13_REG 50
#define R9_REG 38
#define XMM2_REG 23
#define PCOM_FALSE 0
#define FLAGS_REG 17
#define PPERM_INVERT 0x20
#define MM6_REG 35
#define MM1_REG 30
#define PPERM_SRC1 0x00
#define PPERM_SRC2 0x10
#define ST1_REG 9
#define ST2_REG 10
#define XMM10_REG 47
#define DI_REG 5
#define DX_REG 1
#define XMM12_REG 49
#define XMM5_REG 26
#define COM_TRUE_P 5
#define XMM4_REG 25
#define COM_TRUE_S 4
#define FPSR_REG 18
#define XMM15_REG 52
#define PPERM_SIGN 0xc0
#define MM0_REG 29
#define BP_REG 6
#define BX_REG 3
#define ST4_REG 12
#define PPERM_INV_SIGN 0xe0
#define FPCR_REG 19
#define R8_REG 37
#define MM5_REG 34
#define PPERM_REVERSE 0x40
#define CX_REG 2
#define SI_REG 4
#define XMM7_REG 28
#define PPERM_ONES 0xa0
#define R11_REG 40
#define MM2_REG 31
#define XMM1_REG 22
#define PPERM_REV_INV 0x60

enum unspec {
  UNSPEC_GOT = 0,
  UNSPEC_GOTOFF = 1,
  UNSPEC_GOTPCREL = 2,
  UNSPEC_GOTTPOFF = 3,
  UNSPEC_TPOFF = 4,
  UNSPEC_NTPOFF = 5,
  UNSPEC_DTPOFF = 6,
  UNSPEC_GOTNTPOFF = 7,
  UNSPEC_INDNTPOFF = 8,
  UNSPEC_PLTOFF = 9,
  UNSPEC_MACHOPIC_OFFSET = 10,
  UNSPEC_PCREL = 11,
  UNSPEC_STACK_ALLOC = 12,
  UNSPEC_SET_GOT = 13,
  UNSPEC_REG_SAVE = 14,
  UNSPEC_DEF_CFA = 15,
  UNSPEC_SET_RIP = 16,
  UNSPEC_SET_GOT_OFFSET = 17,
  UNSPEC_MEMORY_BLOCKAGE = 18,
  UNSPEC_STACK_CHECK = 19,
  UNSPEC_TP = 20,
  UNSPEC_TLS_GD = 21,
  UNSPEC_TLS_LD_BASE = 22,
  UNSPEC_TLSDESC = 23,
  UNSPEC_TLS_IE_SUN = 24,
  UNSPEC_SCAS = 25,
  UNSPEC_FNSTSW = 26,
  UNSPEC_SAHF = 27,
  UNSPEC_PARITY = 28,
  UNSPEC_FSTCW = 29,
  UNSPEC_ADD_CARRY = 30,
  UNSPEC_FLDCW = 31,
  UNSPEC_REP = 32,
  UNSPEC_LD_MPIC = 33,
  UNSPEC_TRUNC_NOOP = 34,
  UNSPEC_DIV_ALREADY_SPLIT = 35,
  UNSPEC_CALL_NEEDS_VZEROUPPER = 36,
  UNSPEC_FIX_NOTRUNC = 37,
  UNSPEC_MASKMOV = 38,
  UNSPEC_MOVMSK = 39,
  UNSPEC_MOVNT = 40,
  UNSPEC_MOVU = 41,
  UNSPEC_RCP = 42,
  UNSPEC_RSQRT = 43,
  UNSPEC_SFENCE = 44,
  UNSPEC_PFRCP = 45,
  UNSPEC_PFRCPIT1 = 46,
  UNSPEC_PFRCPIT2 = 47,
  UNSPEC_PFRSQRT = 48,
  UNSPEC_PFRSQIT1 = 49,
  UNSPEC_MFENCE = 50,
  UNSPEC_LFENCE = 51,
  UNSPEC_PSADBW = 52,
  UNSPEC_LDDQU = 53,
  UNSPEC_MS_TO_SYSV_CALL = 54,
  UNSPEC_COPYSIGN = 55,
  UNSPEC_IEEE_MIN = 56,
  UNSPEC_IEEE_MAX = 57,
  UNSPEC_SIN = 58,
  UNSPEC_COS = 59,
  UNSPEC_FPATAN = 60,
  UNSPEC_FYL2X = 61,
  UNSPEC_FYL2XP1 = 62,
  UNSPEC_FRNDINT = 63,
  UNSPEC_FIST = 64,
  UNSPEC_F2XM1 = 65,
  UNSPEC_TAN = 66,
  UNSPEC_FXAM = 67,
  UNSPEC_FRNDINT_FLOOR = 68,
  UNSPEC_FRNDINT_CEIL = 69,
  UNSPEC_FRNDINT_TRUNC = 70,
  UNSPEC_FRNDINT_MASK_PM = 71,
  UNSPEC_FIST_FLOOR = 72,
  UNSPEC_FIST_CEIL = 73,
  UNSPEC_SINCOS_COS = 74,
  UNSPEC_SINCOS_SIN = 75,
  UNSPEC_XTRACT_FRACT = 76,
  UNSPEC_XTRACT_EXP = 77,
  UNSPEC_FSCALE_FRACT = 78,
  UNSPEC_FSCALE_EXP = 79,
  UNSPEC_FPREM_F = 80,
  UNSPEC_FPREM_U = 81,
  UNSPEC_FPREM1_F = 82,
  UNSPEC_FPREM1_U = 83,
  UNSPEC_C2_FLAG = 84,
  UNSPEC_FXAM_MEM = 85,
  UNSPEC_SP_SET = 86,
  UNSPEC_SP_TEST = 87,
  UNSPEC_SP_TLS_SET = 88,
  UNSPEC_SP_TLS_TEST = 89,
  UNSPEC_PSHUFB = 90,
  UNSPEC_PSIGN = 91,
  UNSPEC_PALIGNR = 92,
  UNSPEC_EXTRQI = 93,
  UNSPEC_EXTRQ = 94,
  UNSPEC_INSERTQI = 95,
  UNSPEC_INSERTQ = 96,
  UNSPEC_BLENDV = 97,
  UNSPEC_INSERTPS = 98,
  UNSPEC_DP = 99,
  UNSPEC_MOVNTDQA = 100,
  UNSPEC_MPSADBW = 101,
  UNSPEC_PHMINPOSUW = 102,
  UNSPEC_PTEST = 103,
  UNSPEC_ROUND = 104,
  UNSPEC_CRC32 = 105,
  UNSPEC_PCMPESTR = 106,
  UNSPEC_PCMPISTR = 107,
  UNSPEC_FMADDSUB = 108,
  UNSPEC_XOP_UNSIGNED_CMP = 109,
  UNSPEC_XOP_TRUEFALSE = 110,
  UNSPEC_XOP_PERMUTE = 111,
  UNSPEC_FRCZ = 112,
  UNSPEC_AESENC = 113,
  UNSPEC_AESENCLAST = 114,
  UNSPEC_AESDEC = 115,
  UNSPEC_AESDECLAST = 116,
  UNSPEC_AESIMC = 117,
  UNSPEC_AESKEYGENASSIST = 118,
  UNSPEC_PCLMUL = 119,
  UNSPEC_PCMP = 120,
  UNSPEC_VPERMIL = 121,
  UNSPEC_VPERMIL2 = 122,
  UNSPEC_VPERMIL2F128 = 123,
  UNSPEC_MASKLOAD = 124,
  UNSPEC_MASKSTORE = 125,
  UNSPEC_CAST = 126,
  UNSPEC_VTESTP = 127,
  UNSPEC_VCVTPH2PS = 128,
  UNSPEC_VCVTPS2PH = 129,
  UNSPEC_BEXTR = 130,
  UNSPEC_RDRAND = 131
};
#define NUM_UNSPEC_VALUES 132
extern const char *const unspec_strings[];

enum unspecv {
  UNSPECV_BLOCKAGE = 0,
  UNSPECV_STACK_PROBE = 1,
  UNSPECV_PROBE_STACK_RANGE = 2,
  UNSPECV_EMMS = 3,
  UNSPECV_LDMXCSR = 4,
  UNSPECV_STMXCSR = 5,
  UNSPECV_FEMMS = 6,
  UNSPECV_CLFLUSH = 7,
  UNSPECV_ALIGN = 8,
  UNSPECV_MONITOR = 9,
  UNSPECV_MWAIT = 10,
  UNSPECV_CMPXCHG = 11,
  UNSPECV_XCHG = 12,
  UNSPECV_LOCK = 13,
  UNSPECV_PROLOGUE_USE = 14,
  UNSPECV_CLD = 15,
  UNSPECV_NOPS = 16,
  UNSPECV_VZEROALL = 17,
  UNSPECV_VZEROUPPER = 18,
  UNSPECV_RDTSC = 19,
  UNSPECV_RDTSCP = 20,
  UNSPECV_RDPMC = 21,
  UNSPECV_LLWP_INTRINSIC = 22,
  UNSPECV_SLWP_INTRINSIC = 23,
  UNSPECV_LWPVAL_INTRINSIC = 24,
  UNSPECV_LWPINS_INTRINSIC = 25,
  UNSPECV_RDFSBASE = 26,
  UNSPECV_RDGSBASE = 27,
  UNSPECV_WRFSBASE = 28,
  UNSPECV_WRGSBASE = 29,
  UNSPECV_SPLIT_STACK_RETURN = 30
};
#define NUM_UNSPECV_VALUES 31
extern const char *const unspecv_strings[];

#endif /* GCC_INSN_CONSTANTS_H */
