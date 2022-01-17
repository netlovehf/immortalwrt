#ifndef SAE_CMM_H
#define SAE_CMM_H

#ifdef DOT11_SAE_SUPPORT

#ifdef DOT11_SAE_OPENSSL_BN
#include "security/crypt_bignum.h"
#include "security/crypt_biginteger.h"
#include "security/bn.h"

#define SAE_BN BIGNUM

#define SAE_BN_INIT(_in) Bignum_Init(_in)
#define SAE_BN_FREE(_in) Bignum_Free(_in)
#define SAE_BN_PRINT(_in) Bignum_Print(_in)
#define SAE_BN_RELEASE_BACK_TO_POOL(_in) Bignum_Free(_in)
#define SAE_BN_COPY(_in, _out) Bignum_Copy(_in, _out)
#define SAE_BN_BIN2BI(_ptr, _len, _out) Bignum_Bin2BI(_ptr, _len, _out)
#define SAE_BN_BI2BIN_WITH_PAD(_in, _ptr, _len, _padlen)                       \
	Bignum_BI2Bin_with_pad(_in, _ptr, _len, _padlen)
#define SAE_BN_GET_LEN(_in) Bignum_getlen(_in)

#define SAE_BN_UCMP(_a, _b) Bignum_UnsignedCompare(_a, _b)
#define SAE_BN_IS_ZERO(_in) Bignum_is_zero(_in)
#define SAE_BN_IS_ONE(_in) Bignum_is_one(_in)
#define SAE_BN_IS_ODD(_in) Bignum_is_odd(_in)
#define SAE_BN_RSHIFT1(_in, _out) Bignum_Shift_Right1(_in, _out)
#define SAE_BN_MOD_LSHIFT1(_in, _p, _out) Bignum_Mod_Shift_Left1(_in, _p, _out)
#define SAE_BN_MOD_LSHIFT(_in, _bit, _p, _out)                                 \
	Bignum_Mod_Shift_Left(_in, _bit, _p, _out)
#define SAE_BN_IS_QUADRATIC_RESIDE(_q, _p, _m)                                 \
	Bignum_is_quadratic_residue(_q, _p)

#define SAE_BN_ADD(_a, _b, _r) Bignum_Add(_a, _b, _r) /* no use */
#define SAE_BN_SUB(_a, _b, _r) Bignum_Sub(_a, _b, _r)
#define SAE_BN_ADD_DW(_inout, _v) Bignum_Add_DW(_inout, _v)

#define SAE_BN_MOD(_a, _p, _r) Bignum_Mod(_a, _p, _r)
#define SAE_BN_MOD_ADD(_a, _b, _p, _r) Bignum_Mod_Add(_a, _b, _p, _r)
#define SAE_BN_MOD_ADD_QUICK(_a, _b, _p, _r)                                   \
	Bignum_Mod_Add_quick(_a, _b, _p, _r)
#define SAE_BN_MOD_SUB(_a, _b, _p, _r) Bignum_Mod_Sub(_a, _b, _p, _r)
#define SAE_BN_MOD_SUB_QUICK(_a, _b, _p, _r)                                   \
	Bignum_Mod_Sub_quick(_a, _b, _p, _r)
#define SAE_BN_MOD_MUL(_a, _b, _p, _r) Bignum_Mod_Mul(_a, _b, _p, _r)
#define SAE_BN_MOD_DIV(_a, _b, _p, _r) Bignum_Mod_Div(_a, _b, _p, _r)
#define SAE_BN_MOD_SQR(_a, _p, _r) Bignum_Mod_Square(_a, _p, _r)
#define SAE_BN_MOD_SQRT(_a, _p, _mont, _r) Bignum_Mod_Sqrt(_a, _p, _r)
#define SAE_BN_MOD_MUL_INV(_a, _p, _r) Bignum_Mod_Mul_Inverse(_a, _p, _r)
#define SAE_BN_MOD_DW(_inout, _v, _rem) Bignum_Mod_DW(_inout, _v, _rem)

#define SAE_BN_MOD_EXP_MONT(_a, _b, _p, _r)                                    \
	Bignum_Montgomery_ExpMod(_a, _b, _p, _r)
#define SAE_LOG_TIME_BEGIN(_timerec) BigInteger_record_time_begin(_timerec)
#define SAE_LOG_TIME_END(_timerec) BigInteger_record_time_end(_timerec)
#define SAE_LOG_TIME_DUMP() BigInteger_dump_time()
#define SAE_GET_RAND_RANGE(_r, _range) Bignum_Get_rand_range(_range, _r)

#else
#include "security/crypt_biginteger.h"

#define SAE_BN BIG_INTEGER

#define SAE_BN_INIT(_in) BigInteger_Init(_in)
#define SAE_BN_FREE(_in) BigInteger_Free(_in)
#define SAE_BN_PRINT(_in) BigInteger_Print(_in)
#define SAE_BN_RELEASE_BACK_TO_POOL(_in)                                       \
	release_temporal_usage_big_interger(_in)
#define SAE_BN_COPY(_in, _out) BigInteger_Copy(_in, _out)
#define SAE_BN_BIN2BI(_ptr, _len, _out) BigInteger_Bin2BI(_ptr, _len, _out)
#define SAE_BN_BI2BIN_WITH_PAD(_in, _ptr, _len, _padlen)                       \
	BigInteger_BI2Bin_with_pad(_in, _ptr, _len, _padlen)
#define SAE_BN_GET_LEN(_in) BigInteger_getlen(_in)
#define SAE_BN_UCMP(_a, _b) BigInteger_UnsignedCompare(_a, _b)
#define SAE_BN_IS_ZERO(_in) BigInteger_is_zero(_in)
#define SAE_BN_IS_ONE(_in) BigInteger_is_one(_in)
#define SAE_BN_IS_ODD(_in) BigInteger_is_odd(_in)
#define SAE_BN_RSHIFT1(_in, _out) BigInteger_Shift_Right1(_in, _out)
#define SAE_BN_MOD_LSHIFT1(_in, _p, _out)                                      \
	BigInteger_Mod_Shift_Left(_in, 1, _p, _out)
#define SAE_BN_MOD_LSHIFT(_in, _bit, _p, _out)                                 \
	BigInteger_Mod_Shift_Left(_in, _bit, _p, _out)
#define SAE_BN_IS_QUADRATIC_RESIDE(_q, _p, _m)                                 \
	BigInteger_is_quadratic_residue(_q, _p, _m)

#define SAE_BN_ADD(_a, _b, _r) BigInteger_Add(_a, _b, _r) /* no use */
#define SAE_BN_SUB(_a, _b, _r) BigInteger_Sub(_a, _b, _r)
#define SAE_BN_ADD_DW(_inout, _v) BigInteger_Add_DW(_inout, _v)

#define SAE_BN_MOD(_a, _p, _r) BigInteger_Mod(_a, _p, _r)
#define SAE_BN_MOD_ADD(_a, _b, _p, _r) BigInteger_Mod_Add(_a, _b, _p, _r)
#define SAE_BN_MOD_ADD_QUICK(_a, _b, _p, _r)                                   \
	BigInteger_Mod_Add_quick(_a, _b, _p, _r)
#define SAE_BN_MOD_SUB(_a, _b, _p, _r) BigInteger_Mod_Sub(_a, _b, _p, _r)
#define SAE_BN_MOD_SUB_QUICK(_a, _b, _p, _r)                                   \
	BigInteger_Mod_Sub_quick(_a, _b, _p, _r)
#define SAE_BN_MOD_MUL(_a, _b, _p, _r) BigInteger_Mod_Mul(_a, _b, _p, _r)
#define SAE_BN_MOD_DIV(_a, _b, _p, _r) BigInteger_Mod_Div(_a, _b, _p, _r)
#define SAE_BN_MOD_SQR(_a, _p, _r) BigInteger_Mod_Square(_a, _p, _r)
#define SAE_BN_MOD_SQRT(_a, _p, _mont, _r)                                     \
	BigInteger_Mod_Sqrt(_a, _p, _mont, _r)
#define SAE_BN_MOD_MUL_INV(_a, _p, _r) BigInteger_Mod_Mul_Inverse(_a, _p, _r)
#define SAE_BN_MOD_DW(_inout, _v, _rem) BigInteger_Mod_DW(_inout, _v, _rem)

#define SAE_BN_MOD_EXP_MONT(_a, _b, _p, _r)                                    \
	BigInteger_Montgomery_ExpMod(_a, _b, _p, _r)
#define SAE_LOG_TIME_BEGIN(_timerec) BigInteger_record_time_begin(_timerec)
#define SAE_LOG_TIME_END(_timerec) BigInteger_record_time_end(_timerec)
#define SAE_LOG_TIME_DUMP() BigInteger_dump_time()
#define SAE_GET_RAND_RANGE(_r, _range) BigInteger_rand_range(_range, _r)

#endif

#define SAE_ECC_3D
#ifdef SAE_ECC_3D
#define SAE_ECC_3D_to_2D(_group_info, _inout)                                  \
	ecc_point_3d_to_2d(_group_info, _inout)
#define SAE_ECC_SET_Z_TO_1(_inout) ecc_point_set_z_to_one(_inout)
#else
#define SAE_ECC_3D_to_2D(_group_info, _inout)
#define SAE_ECC_SET_Z_TO_1(_inout)

#endif
#define EID_EXT_PASSWORD_IDENTIFIER 33
#define EID_EXT_REJECTED_GROUP 92
#define SAE_MAX_PWD_ID 40 /* this parameter is not defined in spec */
#define SAE_TOKEN_KEY_LEN 6 /* this parameter is not defined in spec */

#define MAX_SAE_KCK_LEN 64 /*SHA512_DIGEST_SIZE */
#define SAE_KCK_LEN 32
#define SAE_PMKID_LEN 16
#define SAE_KEYSEED_KEY_LEN 32
#define SAE_MAX_PRIME_LEN 1024
#define SAE_MAX_ECC_PRIME_LEN 66
#define SAE_COMMIT_MAX_LEN (2 + 3 * SAE_MAX_PRIME_LEN)
#define SAE_CONFIRM_MAX_LEN (2 + SAE_MAX_PRIME_LEN)

#define SAE_COMMIT_SEQ 1
#define SAE_CONFIRM_SEQ 2

#define MAX_SIZE_OF_ALLOWED_GROUP 2

#define DOT11RSNASAESYNC 5

#define SAE_SILENTLY_DISCARDED 65535
#define SAE_MAX_SEND_CONFIRM 65535

#define MAX_SAE_GROUP 32
#define SAE_DEFAULT_GROUP SAE_DEFAULT_GROUP_ECC
#define SAE_DEFAULT_GROUP_ECC 19
#define SAE_DEFAULT_GROUP_FFC 5

#define ECC_POINT_MUL(_point, _scalar, _ec_group_bi, _ec_point_res)            \
	ecc_point_mul_windowed(_point, _scalar, _ec_group_bi, _ec_point_res)

#define SET_NOTHING_STATE(_pSaeIns)                                            \
	{                                                                      \
		if (_pSaeIns->pParentSaeCfg &&                                 \
		    ((_pSaeIns->state == SAE_COMMITTED) ||                     \
		     (_pSaeIns->state == SAE_CONFIRMED)))                      \
			_pSaeIns->pParentSaeCfg->open--;                       \
		_pSaeIns->state = SAE_NOTHING;                                 \
	}

#define SET_COMMITTED_STATE(_pSaeIns)                                          \
	{                                                                      \
		if (_pSaeIns->pParentSaeCfg &&                                 \
		    ((_pSaeIns->state == SAE_NOTHING) ||                       \
		     (_pSaeIns->state == SAE_ACCEPTED)))                       \
			_pSaeIns->pParentSaeCfg->open++;                       \
		_pSaeIns->state = SAE_COMMITTED;                               \
	}

#define SET_CONFIRMED_STATE(_pSaeIns)                                          \
	{                                                                      \
		if (_pSaeIns->pParentSaeCfg &&                                 \
		    ((_pSaeIns->state == SAE_NOTHING) ||                       \
		     (_pSaeIns->state == SAE_ACCEPTED)))                       \
			_pSaeIns->pParentSaeCfg->open++;                       \
		_pSaeIns->state = SAE_CONFIRMED;                               \
	}

#define SET_ACCEPTED_STATE(_pSaeIns)                                           \
	{                                                                      \
		if (_pSaeIns->pParentSaeCfg &&                                 \
		    ((_pSaeIns->state == SAE_COMMITTED) ||                     \
		     (_pSaeIns->state == SAE_CONFIRMED)))                      \
			_pSaeIns->pParentSaeCfg->open--;                       \
		_pSaeIns->state = SAE_ACCEPTED;                                \
	}

typedef enum {
	SAE_NOTHING,
	SAE_COMMITTED,
	SAE_CONFIRMED,
	SAE_ACCEPTED
} SAE_STATE_TYPE,
	*PSAE_STATE_TYPE;

struct pwd_id_list {
	DL_LIST list;
	UCHAR pwd[LEN_PSK + 1];
	UCHAR pwd_id[SAE_MAX_PWD_ID + 1];
};

typedef struct __SAE_GROUP_OP SAE_GROUP_OP;

typedef struct __SAE_INSTANCE SAE_INSTANCE;

typedef struct __SAE_CFG SAE_CFG;

struct __SAE_GROUP_OP {
	VOID (*sae_group_init)(IN SAE_INSTANCE *pSaeIns, IN INT32 group);
	VOID (*sae_group_deinit)(IN SAE_INSTANCE *pSaeIns);
	VOID(*sae_cn_confirm)
	(IN SAE_INSTANCE *pSaeIns, IN UCHAR is_send, OUT UCHAR *confirm);
	USHORT(*sae_parse_commit_element)
	(IN SAE_INSTANCE *pSaeIns, IN UCHAR **pos, IN UCHAR *end);
	UCHAR(*sae_derive_commit_element)
	(IN SAE_INSTANCE *pSaeIns, IN SAE_BN *mask);
	USHORT (*sae_derive_pwe)(IN SAE_INSTANCE *pSaeIns);
	USHORT (*sae_derive_pwe_pt)(IN SAE_INSTANCE *pSaeIns);
	UCHAR (*sae_derive_k)(IN SAE_INSTANCE *pSaeIns, OUT UCHAR *k);
	USHORT (*sae_reflection_check)(IN SAE_INSTANCE *pSaeIns);
};

/* NdisGetSystemUpTime */
typedef struct __SAE_TIME_INTERVAL {
	ULONG derive_pwe_time;
	ULONG parse_commit_scalar_time;
	ULONG parse_commit_element_time;
	ULONG derive_commit_scalar_time;
	ULONG derive_commit_element_time;
	ULONG derive_k_time;
	ULONG derive_pmk_time;
} SAE_TIME_INTERVAL, *PSAE_TIME_INTERVAL;
struct sae_pt {
	struct sae_pt *next;
	USHORT group;
	VOID *pt;
};

enum {
	PWE_MIXED = 0,
	PWE_LOOPING_ONLY, /* hunting-and-pecking only */
	PWE_HASH_ONLY, /* hash-to-element only */
	MAX_PWE_METHOD,
};

struct sae_capability {
	UCHAR gen_pwe_method; /* 0: mixed, 1: hunting-and-pecking only, 2: hash-to-element only */
#ifdef DOT11_SAE_PWD_ID_SUPPORT
	UCHAR pwd_id_only;
#endif
};

struct __SAE_INSTANCE {
	SAE_STATE_TYPE state;
	USHORT send_confirm;
	USHORT last_peer_sc;
	UCHAR pmk[LEN_PMK];
	SAE_BN *peer_commit_scalar;
	USHORT group;
	INT8 sync;
	UINT8 support_group_idx;
	UCHAR kck[MAX_SAE_KCK_LEN];
	UCHAR kck_len;
	SAE_BN *own_commit_scalar;
	VOID *own_commit_element;
	VOID *peer_commit_element;
	VOID *pwe;
	SAE_BN *sae_rand;
	UINT32 prime_len;
	UINT32 order_len;
	VOID *group_info;
	VOID *group_info_bi;
	SAE_BN *prime;
	SAE_BN *order;
	UCHAR *anti_clogging_token;
	UINT32 anti_clogging_token_len;
	USHORT peer_send_confirm;
	UCHAR need_recalculate_key;
	struct pwd_id_list *pwd_id_ptr;
	UCHAR is_pwd_id_only;
	/* peer_pwd_id is temp pointer only for BadId case,
	  * it is not expected to use this for successful case due to this pointer is pointed to packet buffer which might be freed */
	UCHAR *peer_pwd_id;
	UINT32 peer_pwd_id_len;
	const SAE_GROUP_OP *group_op;
	SAE_TIME_INTERVAL sae_cost_time;

	VOID *pt;
	UCHAR peer_rejected_group[12];
	UINT32 peer_rejected_group_len;
	/************************************************/
	/* if the parameter is assigned before sae_group_allowed*/
	/* the parameter ahead of "valid" will be clear **********/
	/************************************************/
	UCHAR valid;
	UCHAR removable;
	RALINK_TIMER_STRUCT sae_retry_timer;
	/* Each instance of the protocol is identified by a tuple consisting of the local MAC address and the peer MAC address */
	UCHAR own_mac[MAC_ADDR_LEN];
	UCHAR peer_mac[MAC_ADDR_LEN];
	UCHAR bssid[MAC_ADDR_LEN];
	UCHAR *psk;
	struct pwd_id_list *pwd_id_list_head;
	SAE_INSTANCE *same_mac_ins;
	SAE_CFG *pParentSaeCfg;
	UINT16 last_rcv_auth_seq;
	UCHAR h2e_connect;
	UINT32 rejected_group; /* bitwise */
};

struct __SAE_CFG {
	SAE_INSTANCE sae_ins[MAX_LEN_OF_MAC_TABLE];
	UCHAR support_group[MAX_SIZE_OF_ALLOWED_GROUP];
	UINT32 open;
	UINT32 total_ins;
	ULONG last_token_key_time;
	UCHAR token_key[SAE_TOKEN_KEY_LEN];
	UINT32 sae_anti_clogging_threshold;
	UCHAR k_iteration_var;
	ULONG dot11RSNASAERetransPeriod;
	struct _RTMP_ADAPTER *pAd;
	NDIS_SPIN_LOCK sae_cfg_lock;
};

typedef struct __BIG_INTEGER_EC_POINT {
	SAE_BN *x;
	SAE_BN *y;
	SAE_BN *z;
	UCHAR z_is_one;
} BIG_INTEGER_EC_POINT, *PBIG_INTEGER_EC_POINT;

/*
 =====================================
	group related
 =====================================
*/

/*
 =====================================
	FFC group related
 =====================================
*/
/* RFC 3526, 4. Group 15 - 3072 Bit MODP
 * Generator: 2
 * Prime: 2^3072 - 2^3008 - 1 + 2^64 * { [2^2942 pi] + 1690314 }
 */
static const UCHAR dh_group15_generator[1] = { 0x02 };
static const UCHAR dh_group15_prime[384] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC9, 0x0F, 0xDA, 0xA2,
	0x21, 0x68, 0xC2, 0x34, 0xC4, 0xC6, 0x62, 0x8B, 0x80, 0xDC, 0x1C, 0xD1,
	0x29, 0x02, 0x4E, 0x08, 0x8A, 0x67, 0xCC, 0x74, 0x02, 0x0B, 0xBE, 0xA6,
	0x3B, 0x13, 0x9B, 0x22, 0x51, 0x4A, 0x08, 0x79, 0x8E, 0x34, 0x04, 0xDD,
	0xEF, 0x95, 0x19, 0xB3, 0xCD, 0x3A, 0x43, 0x1B, 0x30, 0x2B, 0x0A, 0x6D,
	0xF2, 0x5F, 0x14, 0x37, 0x4F, 0xE1, 0x35, 0x6D, 0x6D, 0x51, 0xC2, 0x45,
	0xE4, 0x85, 0xB5, 0x76, 0x62, 0x5E, 0x7E, 0xC6, 0xF4, 0x4C, 0x42, 0xE9,
	0xA6, 0x37, 0xED, 0x6B, 0x0B, 0xFF, 0x5C, 0xB6, 0xF4, 0x06, 0xB7, 0xED,
	0xEE, 0x38, 0x6B, 0xFB, 0x5A, 0x89, 0x9F, 0xA5, 0xAE, 0x9F, 0x24, 0x11,
	0x7C, 0x4B, 0x1F, 0xE6, 0x49, 0x28, 0x66, 0x51, 0xEC, 0xE4, 0x5B, 0x3D,
	0xC2, 0x00, 0x7C, 0xB8, 0xA1, 0x63, 0xBF, 0x05, 0x98, 0xDA, 0x48, 0x36,
	0x1C, 0x55, 0xD3, 0x9A, 0x69, 0x16, 0x3F, 0xA8, 0xFD, 0x24, 0xCF, 0x5F,
	0x83, 0x65, 0x5D, 0x23, 0xDC, 0xA3, 0xAD, 0x96, 0x1C, 0x62, 0xF3, 0x56,
	0x20, 0x85, 0x52, 0xBB, 0x9E, 0xD5, 0x29, 0x07, 0x70, 0x96, 0x96, 0x6D,
	0x67, 0x0C, 0x35, 0x4E, 0x4A, 0xBC, 0x98, 0x04, 0xF1, 0x74, 0x6C, 0x08,
	0xCA, 0x18, 0x21, 0x7C, 0x32, 0x90, 0x5E, 0x46, 0x2E, 0x36, 0xCE, 0x3B,
	0xE3, 0x9E, 0x77, 0x2C, 0x18, 0x0E, 0x86, 0x03, 0x9B, 0x27, 0x83, 0xA2,
	0xEC, 0x07, 0xA2, 0x8F, 0xB5, 0xC5, 0x5D, 0xF0, 0x6F, 0x4C, 0x52, 0xC9,
	0xDE, 0x2B, 0xCB, 0xF6, 0x95, 0x58, 0x17, 0x18, 0x39, 0x95, 0x49, 0x7C,
	0xEA, 0x95, 0x6A, 0xE5, 0x15, 0xD2, 0x26, 0x18, 0x98, 0xFA, 0x05, 0x10,
	0x15, 0x72, 0x8E, 0x5A, 0x8A, 0xAA, 0xC4, 0x2D, 0xAD, 0x33, 0x17, 0x0D,
	0x04, 0x50, 0x7A, 0x33, 0xA8, 0x55, 0x21, 0xAB, 0xDF, 0x1C, 0xBA, 0x64,
	0xEC, 0xFB, 0x85, 0x04, 0x58, 0xDB, 0xEF, 0x0A, 0x8A, 0xEA, 0x71, 0x57,
	0x5D, 0x06, 0x0C, 0x7D, 0xB3, 0x97, 0x0F, 0x85, 0xA6, 0xE1, 0xE4, 0xC7,
	0xAB, 0xF5, 0xAE, 0x8C, 0xDB, 0x09, 0x33, 0xD7, 0x1E, 0x8C, 0x94, 0xE0,
	0x4A, 0x25, 0x61, 0x9D, 0xCE, 0xE3, 0xD2, 0x26, 0x1A, 0xD2, 0xEE, 0x6B,
	0xF1, 0x2F, 0xFA, 0x06, 0xD9, 0x8A, 0x08, 0x64, 0xD8, 0x76, 0x02, 0x73,
	0x3E, 0xC8, 0x6A, 0x64, 0x52, 0x1F, 0x2B, 0x18, 0x17, 0x7B, 0x20, 0x0C,
	0xBB, 0xE1, 0x17, 0x57, 0x7A, 0x61, 0x5D, 0x6C, 0x77, 0x09, 0x88, 0xC0,
	0xBA, 0xD9, 0x46, 0xE2, 0x08, 0xE2, 0x4F, 0xA0, 0x74, 0xE5, 0xAB, 0x31,
	0x43, 0xDB, 0x5B, 0xFC, 0xE0, 0xFD, 0x10, 0x8E, 0x4B, 0x82, 0xD1, 0x20,
	0xA9, 0x3A, 0xD2, 0xCA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
static const UCHAR dh_group15_order[384] = {
	0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE4, 0x87, 0xED, 0x51,
	0x10, 0xB4, 0x61, 0x1A, 0x62, 0x63, 0x31, 0x45, 0xC0, 0x6E, 0x0E, 0x68,
	0x94, 0x81, 0x27, 0x04, 0x45, 0x33, 0xE6, 0x3A, 0x01, 0x05, 0xDF, 0x53,
	0x1D, 0x89, 0xCD, 0x91, 0x28, 0xA5, 0x04, 0x3C, 0xC7, 0x1A, 0x02, 0x6E,
	0xF7, 0xCA, 0x8C, 0xD9, 0xE6, 0x9D, 0x21, 0x8D, 0x98, 0x15, 0x85, 0x36,
	0xF9, 0x2F, 0x8A, 0x1B, 0xA7, 0xF0, 0x9A, 0xB6, 0xB6, 0xA8, 0xE1, 0x22,
	0xF2, 0x42, 0xDA, 0xBB, 0x31, 0x2F, 0x3F, 0x63, 0x7A, 0x26, 0x21, 0x74,
	0xD3, 0x1B, 0xF6, 0xB5, 0x85, 0xFF, 0xAE, 0x5B, 0x7A, 0x03, 0x5B, 0xF6,
	0xF7, 0x1C, 0x35, 0xFD, 0xAD, 0x44, 0xCF, 0xD2, 0xD7, 0x4F, 0x92, 0x08,
	0xBE, 0x25, 0x8F, 0xF3, 0x24, 0x94, 0x33, 0x28, 0xF6, 0x72, 0x2D, 0x9E,
	0xE1, 0x00, 0x3E, 0x5C, 0x50, 0xB1, 0xDF, 0x82, 0xCC, 0x6D, 0x24, 0x1B,
	0x0E, 0x2A, 0xE9, 0xCD, 0x34, 0x8B, 0x1F, 0xD4, 0x7E, 0x92, 0x67, 0xAF,
	0xC1, 0xB2, 0xAE, 0x91, 0xEE, 0x51, 0xD6, 0xCB, 0x0E, 0x31, 0x79, 0xAB,
	0x10, 0x42, 0xA9, 0x5D, 0xCF, 0x6A, 0x94, 0x83, 0xB8, 0x4B, 0x4B, 0x36,
	0xB3, 0x86, 0x1A, 0xA7, 0x25, 0x5E, 0x4C, 0x02, 0x78, 0xBA, 0x36, 0x04,
	0x65, 0x0C, 0x10, 0xBE, 0x19, 0x48, 0x2F, 0x23, 0x17, 0x1B, 0x67, 0x1D,
	0xF1, 0xCF, 0x3B, 0x96, 0x0C, 0x07, 0x43, 0x01, 0xCD, 0x93, 0xC1, 0xD1,
	0x76, 0x03, 0xD1, 0x47, 0xDA, 0xE2, 0xAE, 0xF8, 0x37, 0xA6, 0x29, 0x64,
	0xEF, 0x15, 0xE5, 0xFB, 0x4A, 0xAC, 0x0B, 0x8C, 0x1C, 0xCA, 0xA4, 0xBE,
	0x75, 0x4A, 0xB5, 0x72, 0x8A, 0xE9, 0x13, 0x0C, 0x4C, 0x7D, 0x02, 0x88,
	0x0A, 0xB9, 0x47, 0x2D, 0x45, 0x55, 0x62, 0x16, 0xD6, 0x99, 0x8B, 0x86,
	0x82, 0x28, 0x3D, 0x19, 0xD4, 0x2A, 0x90, 0xD5, 0xEF, 0x8E, 0x5D, 0x32,
	0x76, 0x7D, 0xC2, 0x82, 0x2C, 0x6D, 0xF7, 0x85, 0x45, 0x75, 0x38, 0xAB,
	0xAE, 0x83, 0x06, 0x3E, 0xD9, 0xCB, 0x87, 0xC2, 0xD3, 0x70, 0xF2, 0x63,
	0xD5, 0xFA, 0xD7, 0x46, 0x6D, 0x84, 0x99, 0xEB, 0x8F, 0x46, 0x4A, 0x70,
	0x25, 0x12, 0xB0, 0xCE, 0xE7, 0x71, 0xE9, 0x13, 0x0D, 0x69, 0x77, 0x35,
	0xF8, 0x97, 0xFD, 0x03, 0x6C, 0xC5, 0x04, 0x32, 0x6C, 0x3B, 0x01, 0x39,
	0x9F, 0x64, 0x35, 0x32, 0x29, 0x0F, 0x95, 0x8C, 0x0B, 0xBD, 0x90, 0x06,
	0x5D, 0xF0, 0x8B, 0xAB, 0xBD, 0x30, 0xAE, 0xB6, 0x3B, 0x84, 0xC4, 0x60,
	0x5D, 0x6C, 0xA3, 0x71, 0x04, 0x71, 0x27, 0xD0, 0x3A, 0x72, 0xD5, 0x98,
	0xA1, 0xED, 0xAD, 0xFE, 0x70, 0x7E, 0x88, 0x47, 0x25, 0xC1, 0x68, 0x90,
	0x54, 0x9D, 0x69, 0x65, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
typedef struct __DH_GROUP_INFO {
	INT32 group_id;
	const UCHAR *generator;
	UINT32 generator_len;
	const UCHAR *prime;
	UINT32 prime_len;
	const UCHAR *order;
	UINT32 order_len;
	UCHAR safe_prime;
} DH_GROUP_INFO, *PDH_GROUP_INFO;

typedef struct __DH_GROUP_INFO_BI {
	INT32 group_id;
	SAE_BN *generator;
	SAE_BN *prime;
	SAE_BN *order;
	UCHAR safe_prime;
	UCHAR is_init;
} DH_GROUP_INFO_BI, *PDH_GROUP_INFO_BI;

#define DH_GROUP_NUM (sizeof(dh_groups) / sizeof(DH_GROUP_INFO))

#define DH_GROUP(id, safe)                                                     \
	{                                                                      \
		id, dh_group##id##_generator,                                  \
			sizeof(dh_group##id##_generator),                      \
			dh_group##id##_prime, sizeof(dh_group##id##_prime),    \
			dh_group##id##_order, sizeof(dh_group##id##_order),    \
			safe                                                   \
	}

#define DH_GROUP_BI(id, safe)                                                  \
	{                                                                      \
		.group_id = id, .safe_prime = safe, .is_init = FALSE           \
	}

/*
 =====================================
	ECC group related
 =====================================
*/

/*
 * RFC 5114, 2.6.
 * Group 19 - 256-bit random ECP group
 */
static const UCHAR ec_group19_prime[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
static const UCHAR ec_group19_order[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBC, 0xE6, 0xFA, 0xAD, 0xA7, 0x17,
	0x9E, 0x84, 0xF3, 0xB9, 0xCA, 0xC2, 0xFC, 0x63, 0x25, 0x51
};
static const UCHAR ec_group19_a[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC

};
static const UCHAR ec_group19_b[] = { 0x5A, 0xC6, 0x35, 0xD8, 0xAA, 0x3A, 0x93,
				      0xE7, 0xB3, 0xEB, 0xBD, 0x55, 0x76, 0x98,
				      0x86, 0xBC, 0x65, 0x1D, 0x06, 0xB0, 0xCC,
				      0x53, 0xB0, 0xF6, 0x3B, 0xCE, 0x3C, 0x3E,
				      0x27, 0xD2, 0x60, 0x4B };

static const UCHAR ec_group19_gx[] = {
	0x6B, 0x17, 0xD1, 0xF2, 0xE1, 0x2C, 0x42, 0x47, 0xF8, 0xBC, 0xE6,
	0xE5, 0x63, 0xA4, 0x40, 0xF2, 0x77, 0x03, 0x7D, 0x81, 0x2D, 0xEB,
	0x33, 0xA0, 0xF4, 0xA1, 0x39, 0x45, 0xD8, 0x98, 0xC2, 0x96

};
static const UCHAR ec_group19_gy[] = { 0x4f, 0xe3, 0x42, 0xe2, 0xfe, 0x1a, 0x7f,
				       0x9b, 0x8e, 0xe7, 0xeb, 0x4a, 0x7c, 0x0f,
				       0x9e, 0x16, 0x2b, 0xce, 0x33, 0x57, 0x6b,
				       0x31, 0x5e, 0xce, 0xcb, 0xb6, 0x40, 0x68,
				       0x37, 0xbf, 0x51, 0xf5 };

static const UCHAR ec_group19_z[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF5

};

#define EC_GROUP19_BITS_OF_R 257

static const UCHAR ec_group19_X[] = {
	0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
};

static const UCHAR ec_group19_R[] = {
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const UCHAR ec_group19_PInverse[] = {
	0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
};

/*
 * RFC 5114, 2.7.
 * Group 20 - 384-bit random ECP group
 */
static const UCHAR ec_group20_prime[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
};
static const UCHAR ec_group20_order[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xC7, 0x63, 0x4D, 0x81, 0xF4, 0x37, 0x2D, 0xDF, 0x58, 0x1A, 0x0D, 0xB2,
	0x48, 0xB0, 0xA7, 0x7A, 0xEC, 0xEC, 0x19, 0x6A, 0xCC, 0xC5, 0x29, 0x73

};
static const UCHAR ec_group20_a[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFC,
};
static const UCHAR ec_group20_b[] = {
	0xB3, 0x31, 0x2F, 0xA7, 0xE2, 0x3E, 0xE7, 0xE4, 0x98, 0x8E, 0x05, 0x6B,
	0xE3, 0xF8, 0x2D, 0x19, 0x18, 0x1D, 0x9C, 0x6E, 0xFE, 0x81, 0x41, 0x12,
	0x03, 0x14, 0x08, 0x8F, 0x50, 0x13, 0x87, 0x5A, 0xC6, 0x56, 0x39, 0x8D,
	0x8A, 0x2E, 0xD1, 0x9D, 0x2A, 0x85, 0xC8, 0xED, 0xD3, 0xEC, 0x2A, 0xEF
};

static const UCHAR ec_group20_gx[] = {
	0xAA, 0x87, 0xCA, 0x22, 0xBE, 0x8B, 0x05, 0x37, 0x8E, 0xB1, 0xC7, 0x1E,
	0xF3, 0x20, 0xAD, 0x74, 0x6E, 0x1D, 0x3B, 0x62, 0x8B, 0xA7, 0x9B, 0x98,
	0x59, 0xF7, 0x41, 0xE0, 0x82, 0x54, 0x2A, 0x38, 0x55, 0x02, 0xF2, 0x5D,
	0xBF, 0x55, 0x29, 0x6C, 0x3A, 0x54, 0x5E, 0x38, 0x72, 0x76, 0x0A, 0xB7
};

static const UCHAR ec_group20_gy[] = {
	0x36, 0x17, 0xde, 0x4a, 0x96, 0x26, 0x2c, 0x6f, 0x5d, 0x9e, 0x98, 0xbf,
	0x92, 0x92, 0xdc, 0x29, 0xf8, 0xf4, 0x1d, 0xbd, 0x28, 0x9a, 0x14, 0x7c,
	0xe9, 0xda, 0x31, 0x13, 0xb5, 0xf0, 0xb8, 0xc0, 0x0a, 0x60, 0xb1, 0xce,
	0x1d, 0x7e, 0x81, 0x9d, 0x7a, 0x43, 0x1d, 0x7c, 0x90, 0xea, 0x0e, 0x5f
};

static const UCHAR ec_group20_z[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xF3,
};

#define EC_GROUP20_BITS_OF_R 385

static const UCHAR ec_group20_X[] = {
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01,
};

static const UCHAR ec_group20_R[] = {
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const UCHAR ec_group20_PInverse[] = {
	0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x0c,
	0x00, 0x00, 0x00, 0x02, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xfa,
	0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
};

/*
 * RFC 5114, 2.8.
 * Group 21 - 521-bit random ECP group
 */
static const UCHAR ec_group21_prime[] = {
	0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
static const UCHAR ec_group21_order[] = {
	0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA,
	0x51, 0x86, 0x87, 0x83, 0xBF, 0x2F, 0x96, 0x6B, 0x7F, 0xCC, 0x01, 0x48,
	0xF7, 0x09, 0xA5, 0xD0, 0x3B, 0xB5, 0xC9, 0xB8, 0x89, 0x9C, 0x47, 0xAE,
	0xBB, 0x6F, 0xB7, 0x1E, 0x91, 0x38, 0x64, 0x09
};
static const UCHAR ec_group21_a[] = {
	0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC
};
static const UCHAR ec_group21_b[] = {
	0x00, 0x00, 0x00, 0x51, 0x95, 0x3E, 0xB9, 0x61, 0x8E, 0x1C, 0x9A, 0x1F,
	0x92, 0x9A, 0x21, 0xA0, 0xB6, 0x85, 0x40, 0xEE, 0xA2, 0xDA, 0x72, 0x5B,
	0x99, 0xB3, 0x15, 0xF3, 0xB8, 0xB4, 0x89, 0x91, 0x8E, 0xF1, 0x09, 0xE1,
	0x56, 0x19, 0x39, 0x51, 0xEC, 0x7E, 0x93, 0x7B, 0x16, 0x52, 0xC0, 0xBD,
	0x3B, 0xB1, 0xBF, 0x07, 0x35, 0x73, 0xDF, 0x88, 0x3D, 0x2C, 0x34, 0xF1,
	0xEF, 0x45, 0x1F, 0xD4, 0x6B, 0x50, 0x3F, 0x00
};

static const UCHAR ec_group21_gx[] = {
	0x00, 0xC6, 0x85, 0x8E, 0x06, 0xB7, 0x04, 0x04, 0xE9, 0xCD, 0x9E,
	0x3E, 0xCB, 0x66, 0x23, 0x95, 0xB4, 0x42, 0x9C, 0x64, 0x81, 0x39,
	0x05, 0x3F, 0xB5, 0x21, 0xF8, 0x28, 0xAF, 0x60, 0x6B, 0x4D, 0x3D,
	0xBA, 0xA1, 0x4B, 0x5E, 0x77, 0xEF, 0xE7, 0x59, 0x28, 0xFE, 0x1D,
	0xC1, 0x27, 0xA2, 0xFF, 0xA8, 0xDE, 0x33, 0x48, 0xB3, 0xC1, 0x85,
	0x6A, 0x42, 0x9B, 0xF9, 0x7E, 0x7E, 0x31, 0xC2, 0xE5, 0xBD, 0x66
};

static const UCHAR ec_group21_gy[] = {
	0x01, 0x18, 0x39, 0x29, 0x6a, 0x78, 0x9a, 0x3b, 0xc0, 0x04, 0x5c,
	0x8a, 0x5f, 0xb4, 0x2c, 0x7d, 0x1b, 0xd9, 0x98, 0xf5, 0x44, 0x49,
	0x57, 0x9b, 0x44, 0x68, 0x17, 0xaf, 0xbd, 0x17, 0x27, 0x3e, 0x66,
	0x2c, 0x97, 0xee, 0x72, 0x99, 0x5e, 0xf4, 0x26, 0x40, 0xc5, 0x50,
	0xb9, 0x01, 0x3f, 0xad, 0x07, 0x61, 0x35, 0x3c, 0x70, 0x86, 0xa2,
	0x72, 0xc2, 0x40, 0x88, 0xbe, 0x94, 0x76, 0x9f, 0xd1, 0x66, 0x50
};

static const UCHAR ec_group21_z[] = {
	0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB
};

#define EC_GROUP21_BITS_OF_R 522

static const UCHAR ec_group21_X[] = {
	0x00,
	0x00,
	0x00,
	0x01,
};

static const UCHAR ec_group21_R[] = {
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const UCHAR ec_group21_PInverse[] = {
	0x00,
	0x00,
	0x00,
	0x01,
};

#define EC_GROUP(id, bits_of_R)                                                \
	{                                                                      \
		id, ec_group##id##_prime, sizeof(ec_group##id##_prime),        \
			ec_group##id##_order, sizeof(ec_group##id##_order),    \
			ec_group##id##_a, sizeof(ec_group##id##_a),            \
			ec_group##id##_b, sizeof(ec_group##id##_b),            \
			ec_group##id##_z, sizeof(ec_group##id##_z),            \
			ec_group##id##_X, sizeof(ec_group##id##_X),            \
			ec_group##id##_R, sizeof(ec_group##id##_R),            \
			ec_group##id##_PInverse,                               \
			sizeof(ec_group##id##_PInverse), bits_of_R             \
	}

#define EC_GROUP_NUM (sizeof(ec_groups) / sizeof(EC_GROUP_INFO))

#define EC_GROUP_BI(id)                                                        \
	{                                                                      \
		.group_id = id, .is_init = FALSE, .mont = NULL,                \
		.is_minus_3 = FALSE                                            \
	}

#endif
#endif /* SAE_CMM_H */
