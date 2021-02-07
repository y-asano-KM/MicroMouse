/* ============================================================ */
/* �t�@�C���� : app_plan.c                                      */
/* �@�\       : �ŒZ�o�H�Z�o�E�i�s��������                      */
/* ============================================================ */
#define SECTION_APP

/* ============================================================ */
/* �C���N���[�h                                                 */
/* ============================================================ */
/* �v���W�F�N�g���� */
#include "prj_cmn_section.h"
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* �J�e�S������ */
#include "app_cmn_option.h"
#include "app_cmn_option_pac.h"

/* �� */
#include "app_map_pac.h"

/* �{�� */
#include "app_plan_pac.h"

/* ============================================================ */
/* �}�N���萔��`                                               */
/* ============================================================ */
/* #define ARRAYSIZE 32 */      /* (MAZESIZE_X�~MAZESIZE_Y�|1)��8 */
#define ARRAYSIZE 3             /* (MAZESIZE_X�~MAZESIZE_Y�|1)��8 */

#define flag U1
#define false 0
#define true 1

/* ============================================================ */
/* �^��`                                                       */
/* ============================================================ */

/* ============================================================ */
/* �֐��v���g�^�C�v�錾(static)                                 */
/* ============================================================ */
static U1 FnU1_Plan_searchdir(U1 x, U1 y, t_direction dir);

/* ============================================================ */
/* �ϐ���`(extern)                                             */
/* ============================================================ */

/* ============================================================ */
/* �ϐ���`(static)                                             */
/* ============================================================ */
static U1 u1s_map[MAZESIZE_X][MAZESIZE_Y];
static U1 u1s_north[ARRAYSIZE];
static U1 u1s_east[ARRAYSIZE];
static U1 u1s_south[ARRAYSIZE];
static U1 u1s_west[ARRAYSIZE];
static U1 u1s_shortestroute_c;  /* �ŒZ�o�H���o�σt���O */
static U1 u1s_bytepos;          /* �ŒZ�o�H���o�o�C�g�ʒu */
static U1 u1s_bitpos;           /* �ŒZ�o�H���o�r�b�g�ʒu */

/* ============================================================ */
/* const�ϐ���`(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* const�ϐ���`(static)                                        */
/* ============================================================ */


/* ============================================================ */
/* �֐��`���}�N����`                                           */
/* ============================================================ */


/* ============================================================ */
/* �֐���`                                                     */
/* ============================================================ */
/* ============================================================ */
/* �֐��� : FnVD_Plan_initmap                                   */
/*          ����Map�̏�����                                     */
/* ����   : �Ȃ�                                                */
/* �߂�l : �Ȃ�                                                */
/* �T�v   : ����Map��S�̂�0xff�A�S�[�����W(x,y)��0�ŏ��������� */
/* ����   : �Ȃ�                                                */
/* ============================================================ */
VD FnVD_Plan_initmap(VD)
{
    U1 u1t_i;
    U1 u1t_j;

    for( u1t_i = (U1)0; u1t_i < MAZESIZE_X; u1t_i++ )           /* ���H�̑傫�������[�v(x���W) */
    {
        for( u1t_j = (U1)0; u1t_j < MAZESIZE_Y; u1t_j++ )       /* ���H�̑傫�������[�v(y���W) */
        {
            u1s_map[u1t_i][u1t_j] = (U1)255;                    /* ���ׂ�255�Ŗ��߂� */
        }
    }

    //�S�[�����W�̕�����0�ɐݒ�
    u1s_map[3][3] = (U1)0;
    /*u1s_map[7][7] = (U1)0;*/
    /*u1s_map[7][8] = (U1)0;*/
    /*u1s_map[8][7] = (U1)0;*/
    /*u1s_map[8][8] = (U1)0;*/
}

/* ============================================================ */
/* �֐��� : FnVD_Plan_makemap                                   */
/*          ����Map���쐬����                                   */
/* ����   : �Ȃ�                                                */
/* �߂�l : �Ȃ�                                                */
/* �T�v   : �Ǐ������Ƃɕ���Map���쐬����                     */
/* ����   : �Ȃ�                                                */
/* ============================================================ */
VD FnVD_Plan_makemap(VD)
{
    U1 u1t_i;
    U1 u1t_j;
    flag bit_change_flag;       /* Map�쐬�I�������ɂ߂邽�߂̃t���O */

    FnVD_Plan_initmap();        /* Map������������ */

    do
    {
        bit_change_flag = (flag)false;                          /* �ύX���Ȃ������ꍇ�ɂ̓��[�v�𔲂��� */
        for( u1t_i = 0; u1t_i < MAZESIZE_X; u1t_i++ )           /* ���H�̑傫�������[�v(x���W) */
        {
            for( u1t_j = 0; u1t_j < MAZESIZE_Y; u1t_j++ )       /* ���H�̑傫�������[�v(y���W) */
            {

                if( u1s_map[u1t_i][u1t_j] == (U1)255 )          /* 255�̏ꍇ�͎��� */
                {
                    continue;
                }

                if( u1t_j < (U1)( MAZESIZE_Y - (U1)1 ) )        /* �͈̓`�F�b�N */
                {
                    if( wall[u1t_i][u1t_j].north == NOWALL )    /* �ǂ��Ȃ���� */
                    {
                        if( u1s_map[u1t_i][ (U1)( u1t_j + (U1)1 ) ] == (U1)255 )        /* �܂��l�������Ă��Ȃ���� */
                        {
                            u1s_map[u1t_i][ (U1)( u1t_j + (U1)1 ) ] = (U1)( u1s_map[u1t_i][u1t_j] + (U1)1 );    /* �l���� */
                            bit_change_flag = (flag)true;       /* �l���X�V���ꂽ���Ƃ����� */
                        }
                    }
                }

                if( u1t_i < (U1)( MAZESIZE_X - (U1)1 ) )        /* �͈̓`�F�b�N */
                {
                    if( wall[u1t_i][u1t_j].east == NOWALL )     /* �ǂ��Ȃ���� */
                    {
                        if( u1s_map[ (U1)( u1t_i + (U1)1 ) ][u1t_j] == (U1)255 )        /* �܂��l�������Ă��Ȃ���� */
                        {
                            u1s_map[ (U1)( u1t_i + (U1)1 ) ][u1t_j] = (U1)( u1s_map[u1t_i][u1t_j] + (U1)1 );    /* �l���� */
                            bit_change_flag = (flag)true;       /* �l���X�V���ꂽ���Ƃ����� */
                        }
                    }
                }

                if( u1t_j > (U1)0 )                             /* �͈̓`�F�b�N */
                {
                    if( wall[u1t_i][u1t_j].south == NOWALL )    /* �ǂ��Ȃ���� */
                    {
                        if( u1s_map[u1t_i][ (U1)( u1t_j - (U1)1 ) ] == (U1)255 )        /* �l�������Ă��Ȃ���� */
                        {
                            u1s_map[u1t_i][ (U1)( u1t_j - (U1)1 ) ] = (U1)( u1s_map[u1t_i][u1t_j] + (U1)1 );    /* �l���� */
                            bit_change_flag = (flag)true;       /* �l���X�V���ꂽ���Ƃ����� */
                        }
                    }
                }

                if( u1t_i > (U1)0 )                             /* �͈̓`�F�b�N */
                {
                    if( wall[u1t_i][u1t_j].west == NOWALL )     /* �ǂ��Ȃ���� */
	                    {
                        if( u1s_map[ (U1)( u1t_i - (U1)1 ) ][u1t_j] == (U1)255 )        /* �l�������Ă��Ȃ���� */
                        {
                            u1s_map[ (U1)( u1t_i - (U1)1 ) ][u1t_j] = (U1)( u1s_map[u1t_i][u1t_j] + (U1)1 );    /* �l���� */
                            bit_change_flag = (flag)true;       /* �l���X�V���ꂽ���Ƃ����� */
                        }
                    }
                }
            }

        }

    }while( bit_change_flag == (flag)true );    /* �S�̂����I���܂ő҂� */

}

/* ============================================================ */
/* �֐��� : FnVD_Plan_shortestroute                             */
/*          �ŒZ�o�H�𒊏o����                                  */
/* ����   : �Ȃ�                                                */
/* �߂�l : �Ȃ�                                                */
/* �T�v   : �쐬��������Map�����ƂɍŒZ�o�H�𒊏o����           */
/* ����   : �Ȃ�                                                */
/* ============================================================ */
VD FnVD_Plan_shortestroute(VD)
{
    U1 u1t_i;
    U1 u1t_j;
    U1 u1t_k;
    U1 u1t_l;
    U1 u1t_m;
    U1 u1t_n;
    t_direction u1t_dir;        /* north=0,east=1,south=2,west=3 */

    U1 u1t_dir_before;
    flag bit_dir_flag;

    u1t_i = (U1)0;                      /* �X�^�[�g�n�_��x���W */
    u1t_j = (U1)0;                      /* �X�^�[�g�n�_��y���W */
    u1t_l = (U1)0;
    u1t_m = (U1)0;
    u1t_n = u1s_map[u1t_i][u1t_j];      /* �X�^�[�g�n�_�̕����}�b�v�l�������l�ݒ� */
    u1t_dir = north;

    u1s_shortestroute_c = (U1)0;
    u1s_bytepos = (U1)0;                /* �ŒZ�o�H���o�o�C�g�ʒu */
    u1s_bitpos = (U1)7;                 /* �ŒZ�o�H���o�r�b�g�ʒu */

    for( u1t_k = (U1)0; u1t_k < ARRAYSIZE; u1t_k++ )    /* ���ׂ�0�Ŗ��߂� */
    {
        u1s_north[u1t_k] = (U1)0;
        u1s_east[u1t_k] = (U1)0;
        u1s_south[u1t_k] = (U1)0;
        u1s_west[u1t_k] = (U1)0;
    }

    do
    {
        bit_dir_flag = (flag)false;
        u1t_dir_before = u1t_dir;           /* �O��l�ێ� */

        if( u1t_j < (U1)( MAZESIZE_Y - (U1)1 ) )    /* �͈̓`�F�b�N */
        {
            if( wall[u1t_i][u1t_j].north == NOWALL )        /* �ǂ��Ȃ���� */
            {
                if( u1s_map[u1t_i][ (U1)( u1t_j + (U1)1 ) ] == (U1)( u1t_n - (U1)1 ) )  /* �����}�b�v�l��-1�ł���� */
                {
                    u1t_dir = north;                /* �i�s������ݒ� */
                    bit_dir_flag = (flag)true;      /* �l���X�V���ꂽ���Ƃ����� */
                }
            }
        }

        if( u1t_i < (U1)( MAZESIZE_X - (U1)1 ) )    /* �͈̓`�F�b�N */
        {
            if( wall[u1t_i][u1t_j].east == NOWALL )         /* �ǂ��Ȃ���� */
            {
                if( u1s_map[ (U1)( u1t_i + (U1)1 ) ][u1t_j] == (U1)( u1t_n - (U1)1 ) ) /* �����}�b�v�l��-1�ł���� */
                {
                    if( bit_dir_flag == (flag)true )        /* �i�s�����ɕ����̉\��������ꍇ */
                    {
                        if( u1t_dir != u1t_dir_before )     /* �O��̐i�s�����ƈ�v����ꍇ�͑O�������D�� */
                        {
                            u1t_dir = east;         /* �i�s������ݒ� */
                            bit_dir_flag = (flag)true;      /* �l���X�V���ꂽ���Ƃ����� */
                        }
                    }
                    else
                    {
                        u1t_dir = east;             /* �i�s������ݒ� */
                        bit_dir_flag = (flag)true;         /* �l���X�V���ꂽ���Ƃ����� */
  
                    }
                }
            }
        }

        if( u1t_j > (U1)0 )                         /* �͈̓`�F�b�N */
        {
            if( wall[u1t_i][u1t_j].south == NOWALL )        /* �ǂ��Ȃ���� */
            {
                if( u1s_map[u1t_i][ (U1)( u1t_j - (U1)1 ) ] == (U1)( u1t_n - (U1)1 ) )  /* �����}�b�v�l��-1�ł���� */
                {
                    if( bit_dir_flag == (flag)true )        /* �i�s�����ɕ����̉\��������ꍇ */
                    {
                        if( u1t_dir != u1t_dir_before )     /* �O��̐i�s�����ƈ�v����ꍇ�͑O�������D�� */
                        {
                            u1t_dir = south;        /* �i�s������ݒ� */
                            bit_dir_flag = (flag)true;      /* �l���X�V���ꂽ���Ƃ����� */
                        }
                    }
                    else
                    {
                        u1t_dir = south;            /* �i�s������ݒ� */
                        bit_dir_flag = (flag)true;          /* �l���X�V���ꂽ���Ƃ����� */
  
                    }
                }
            }
        }

        if( u1t_i > (U1)0 )                         /* �͈̓`�F�b�N */
        {
            if( wall[u1t_i][u1t_j].west == NOWALL )         /* �ǂ��Ȃ���� */
            {
                if( u1s_map[ (U1)( u1t_i - (U1)1 ) ][u1t_j] == (U1)( u1t_n - (U1)1 ) )  /* �����}�b�v�l��-1�ł���� */
                {
                    if( bit_dir_flag == (flag)true )        /* �i�s�����ɕ����̉\��������ꍇ */
                    {
                        if( u1t_dir != u1t_dir_before )     /* �O��̐i�s�����ƈ�v����ꍇ�͑O�������D�� */
                        {
                            u1t_dir = west;         /* �i�s������ݒ� */
                            bit_dir_flag = (flag)true;      /* �l���X�V���ꂽ���Ƃ����� */
                        }
                    }
                    else
                    {
                        u1t_dir = west;             /* �i�s������ݒ� */
                        bit_dir_flag = (flag)true;          /* �l���X�V���ꂽ���Ƃ����� */
  
                    }
                }
            }
        }

        if( bit_dir_flag == (flag)true )        /* �i�s������ێ� */
        {
            if( u1t_dir == north )
            {
                u1s_north[u1t_l] |= ( (U1)1 << (U1)( (U1)7 - u1t_m ) );
            }
            if( u1t_dir == east )
            {
                u1s_east[u1t_l] |= ( (U1)1 << (U1)( (U1)7 - u1t_m ) );
            }
            if( u1t_dir == south )
            {
                u1s_south[u1t_l] |= ( (U1)1 << (U1)( (U1)7 - u1t_m ) );
            }
            if( u1t_dir == west )
            {
                u1s_west[u1t_l] |= ( (U1)1 << (U1)( (U1)7 - u1t_m ) );
            }

            u1t_m++;
            if( u1t_m > (U1)7 )
            {
                u1t_l++;
                u1t_m = 0;
            }
        }

    }while( bit_dir_flag == (flag)true );      /* �S�̂����I���܂ő҂� */

    u1s_shortestroute_c = (U1)1;               /* �ŒZ�o�H���o�� */

}

/* ============================================================ */
/* �֐��� : FnU1_Plan_indicatedir                               */
/*          �o�H���w������                                      */
/* ����   : x,y �F���ݒn���(x,y)                               */
/*          dir �F���݂̐i�s����                                */
/* �߂�l : u1t_ret �Fnorth=0,east=1,south=2,west=3             */
/* �T�v   : ���ݒn���(x,y)����o�H(�i�s����)���Z�o����         */
/* ����   : �Ȃ�                                                */
/* ============================================================ */
U1 FnU1_Plan_indicatedir(U1 x, U1 y, t_direction dir)
{
    U1 u1t_n;
    U1 u1t_ret;         /* north=0,east=1,south=2,west=3 */
    U1 u1t_temp;
    
    u1t_n = u1s_map[x][y];      /* �Ώےn�_�̕����}�b�v�l�������l�ݒ� */
    u1t_ret = (U1)255;

    if( u1t_n == (U1)255 )
    {
        /* �ŒZ�o�H������ł��Ȃ��������߁A�ǔ���UNKNOWN�ӏ�(�����}�b�v�l�������l(255)�̉ӏ�)�̑{�� */
        u1t_ret = FnU1_Plan_searchdir( x, y, dir );
    }
    else
    {
        if( u1s_shortestroute_c == (U1)0 )  /* �ŒZ�o�H�����o�̏ꍇ */
        {
            FnVD_Plan_shortestroute();      /* �ŒZ�o�H���o */
        }

        u1t_temp = u1s_north[u1s_bytepos];
        u1t_temp &= ( (U1)1 << u1s_bitpos );
        if( u1t_temp != (U1)0 )
        {
            u1t_ret = north;                /* �i�s�����@�k */
        }
        if( u1t_ret == (U1)255 )
        {
            u1t_temp = u1s_east[u1s_bytepos];
            u1t_temp &= ( (U1)1 << u1s_bitpos );
            if( u1t_temp != (U1)0 )
            {
                u1t_ret = east;             /* �i�s�����@�� */
            }
        }
        if( u1t_ret == (U1)255 )
        {
            u1t_temp = u1s_south[u1s_bytepos];
            u1t_temp &= ( (U1)1 << u1s_bitpos );
            if( u1t_temp != (U1)0 )
            {
                u1t_ret = south;            /* �i�s�����@�� */
            }
        }
        if( u1t_ret == (U1)255 )
        {
            u1t_temp = u1s_west[u1s_bytepos];
            u1t_temp &= ( (U1)1 << u1s_bitpos );
            if( u1t_temp != (U1)0 )
            {
                u1t_ret = west;             /* �i�s�����@�� */
            }
        }

        if( u1s_bitpos == (U1)0 )
        {
            u1s_bytepos++;
            u1s_bitpos = (U1)7;
        }
        else
        {
            u1s_bitpos--;
        }

    }

    return(u1t_ret);

}

/* ============================================================ */
/* �֐��� : FnU1_Plan_searchdir                                 */
/*          �ŒZ�o�H��������Ȃ��ꍇ�̌o�H���w������            */
/* ����   : x,y �F���ݒn���(x,y)                               */
/*          dir �F���݂̐i�s����(north=0,east=1,south=2,west=3) */
/* �߂�l : u1t_ret_temp �Fnorth=0,east=1,south=2,west=3        */
/* �T�v   : ���ݒn���(x,y)����o�H(�i�s����)���Z�o����         */
/*          �D�揇:�S�[�������������������i���E���܁����       */
/* ����   : �Ȃ�                                                */
/* ============================================================ */
static U1 FnU1_Plan_searchdir(U1 x, U1 y, t_direction dir)
{
    t_direction u1t_dir;        /* north=0,east=1,south=2,west=3 */
    U1 u1t_ret_temp;            /* north=0,east=1,south=2,west=3,�����l=255 */
    U1 u1t_priority;            /* �D�揇�i�S�[��:8�A������:4�A���i:2�A�E����:1�j */
    U1 u1t_priority_temp;       /* �D�揇�i�S�[��:8�A������:4�A���i:2�A�E����:1�j */

    u1t_dir = dir;
    u1t_ret_temp = (U1)255;
    u1t_priority = (U1)0;
    u1t_priority_temp = (U1)0;

    if( y < (U1)( MAZESIZE_Y - (U1)1 ) )        /* �͈̓`�F�b�N */
    {
        if( wall[x][y].north == NOWALL )        /* �ǂ��Ȃ���� */
        {
            u1t_ret_temp = north;               /* �i�s�����@�k(���ݒ�) */
            if( u1s_map[x][ (U1)( y + (U1)1 ) ] == (U1)0 )      /* �S�[���������� */
            {
                u1t_priority = (U1)8;           /* �i�s�������� */
            }
            else
            {
                if( wall[x][ (U1)( y + (U1)1 ) ].north == UNKNOWN )     /* �k�ɂP�}�X�i�񂾐����x���T�����Ă��Ȃ������� */
                {
                    u1t_priority = (U1)4;
                }

                if( u1t_dir == north )          /* �i�s����(�k)�����i���� */
                {
                    u1t_priority += (U1)2;
                }
                else if( u1t_dir != south )     /* �i�s����(�k)���E���ܕ��� */
                {
                    u1t_priority += (U1)1;
                }
            }
        }
    }

    if( u1t_priority < (U1)8 )
    {
        if( x < (U1)( MAZESIZE_X - (U1)1 ) )    /* �͈̓`�F�b�N */
        {
            if( wall[x][y].east == NOWALL )     /* �ǂ��Ȃ���� */
            {

                if( u1s_map[ (U1)( x + (U1)1 ) ][y] == (U1)0 )          /* �S�[���������� */
                {
                    u1t_priority_temp = (U1)8;  /* �i�s�������� */
                }
                else
                {
                    if( wall[ (U1)( x + (U1)1 ) ][y].east == UNKNOWN ) /* ���ɂP�}�X�i�񂾐����x���T�����Ă��Ȃ������� */
                    {
                        u1t_priority_temp = (U1)4;
                    }

                    if( u1t_dir == east )       /* �i�s����(��)�����i���� */
                    {
                        u1t_priority_temp += (U1)2;
                    }
                    else if( u1t_dir != west )  /* �i�s����(��)���E���ܕ��� */
                    {
                        u1t_priority_temp += (U1)1;
                    }
                }

                if( u1t_priority_temp > u1t_priority )
                {
                    u1t_ret_temp = east;        /* �i�s�����@��(�X�V) */
                    u1t_priority = u1t_priority_temp;
                    u1t_priority_temp = (U1)0;  /* �N���A���� */
                }
            }
        }
    }

    if( u1t_priority < (U1)8 )
    {
        if( y > (U1)0 )                         /* �͈̓`�F�b�N */
        {
            if( wall[x][y].south == NOWALL )    /* �ǂ��Ȃ���� */
            {
                if( u1s_map[x][ (U1)( y - (U1)1 ) ] == (U1)0 )  /* �S�[���������� */
                {
                    u1t_priority_temp = (U1)8;  /* �i�s�������� */
                }
                else
                {
                    if( wall[x][ (U1)( y - (U1)1 ) ].south == UNKNOWN ) /* ��ɂP�}�X�i�񂾐����x���T�����Ă��Ȃ������� */
                    {
                        u1t_priority_temp = (U1)4;
                    }

                    if( u1t_dir == south )      /* �i�s����(��)�����i���� */
                    {
                        u1t_priority_temp += (U1)2;
                    }
                    else if( u1t_dir != north ) /* �i�s����(��)���E���ܕ��� */
                    {
                        u1t_priority_temp += (U1)1;
                    }
                }

                if( u1t_priority_temp > u1t_priority )
                {
                    u1t_ret_temp = south;       /* �i�s�����@��(�X�V) */
                    u1t_priority = u1t_priority_temp;
                    u1t_priority_temp = (U1)0;  /* �N���A���� */
                }
            }
        }
    }

    if( u1t_priority < (U1)8 )
    {
        if( y > (U1)0 )                         /* �͈̓`�F�b�N */
        {
            if( wall[x][y].south == NOWALL )    /* �ǂ��Ȃ���� */
            {
                if( u1s_map[ (U1)( x - (U1)1 ) ][y] == (U1)0 )  /* �S�[���������� */
                {
                    u1t_priority_temp = (U1)8;  /* �i�s�������� */
                }
                else
                {
                    if( wall[ (U1)( x - (U1)1 ) ][y].west == UNKNOWN )  /* ���ɂP�}�X�i�񂾐����x���T�����Ă��Ȃ������� */
                    {
                        u1t_priority_temp = (U1)4;
                    }

                    if( u1t_dir == west )       /* �i�s����(��)�����i���� */
                    {
                        u1t_priority_temp += (U1)2;
                    }
                    else if( u1t_dir != east )  /* �i�s����(��)���E���ܕ��� */
                    {
                        u1t_priority_temp += (U1)1;
                    }
                }

                if( u1t_priority_temp > u1t_priority )
                {
                    u1t_ret_temp = west;        /* �i�s�����@��(�X�V) */
                    u1t_priority = u1t_priority_temp;
                }
            }
        }
    }

    return(u1t_ret_temp);

}
