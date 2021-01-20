

#define MAZESIZE_X (16)       /* ���H�̑傫��(MAZESIZE_X x MAZESIZE_Y)���H */
#define MAZESIZE_Y (16)       /* ���H�̑傫��(MAZESIZE_X x MAZESIZE_Y)���H */

#define UNKNOWN 2             /* �ǂ����邩�Ȃ�������Ȃ���Ԃ̏ꍇ�̒l */
#define NOWALL 0              /* �ǂ��Ȃ��΂����̒l */
#define WALL 1                /* �ǂ�����ꍇ�̒l */
#define VWALL 3               /* ���z�ǂ̒l(���g�p) */

#define MASK_SEARCH 0x01      /* �T�����s�p�}�X�N�l.�Ǐ��Ƃ��̒l��AND�l���O�iNOWALL�j�Ȃ�ǂȂ�or���T����� */
#define MASK_SECOND 0x03      /* �ŒZ���s�p�}�X�N�l.�Ǐ��Ƃ��̒l��AND�l���O�iNOWALL�j�Ȃ�ǂȂ� */

/* CONV_SEN2WALL() */
#define CONV_SEN2WALL(w) ((w) ? WALL : NOWALL)			//�Z���T��񂩂�Ǐ��֕ϊ�

/*?���p�������񋓌^?*/
typedef enum
{
  north=0,       /* �k */
  east=1,        /* �� */
  south=2,       /* �� */
  west=3,        /* �� */
}t_direction;

/*?�������猩�������������񋓌^?*/
typedef enum
{
  front=0,       /* �O */
  right=1,       /* �E */
  rear=2,        /* �� */
  left=3,        /* �� */
  unknown,       /* �����s�� */
}t_local_dir;


/*?���Ԉʒu���?*/
typedef struct
{
  short x;           /* ���Ԉʒu��X���W(��������) */
  short y;           /* ���Ԉʒu��Y���W(��k����) */
  t_direction dir;   /* ���ԕ��p */
}t_position;


/*?�Ǐ����i�[����\����(�r�b�g�t�B�[���h)?*/
typedef struct
{
  unsigned char north:2; /* �k�̕Ǐ��?*/
  unsigned char east:2;  /* ���̕Ǐ��?*/
  unsigned char south:2; /* ��̕Ǐ��?*/
  unsigned char west:2;  /* ���̕Ǐ��?*/
}t_wall;


static t_position mypos;                    /* ���Ԉʒu���?*/
static t_wall wall[MAZESIZE_X][MAZESIZE_Y]; /* �ǂ̏����i�[����\���̔z��?*/





/* RCG �f�o�b�O�p*/
typedef struct
{
  unsigned char bl_wall_with; /*?�ǗL��?�ǖ���:OFF(0)?�ǂ���:ON(1)?*/
  unsigned char bl_wall_data_valid;  /*?�ǃf�[�^�L������?����:OFF(0)?�L��:ON(1)?*/
}ST_WALLDATA;


typedef struct
{
  ST_WALLDATA wall_f; /*?�O�Ǐ��?*/
  ST_WALLDATA wall_r;  /*?�E�Ǐ��?*/
  ST_WALLDATA wall_l;  /*?�E�Ǐ��?*/
}ST_WALLINFO;


ST_WALLINFO wallinfo;


void Fn_MAP_init(void);

/*?============================================================?*/
/*?�֐���?:?Fn_MAP_init            ?????????????????????????????*/
/*??????????�Ǐ��Ǝ��Ԉʒu��񏉊���                          */
/*?����???:?�Ȃ�????????????????????????????????????????????????*/
/*?�߂�l?:?�Ȃ�????????????????????????????????????????????????*/
/*?�T�v???:?�Ǐ��Ǝ��Ԉʒu��񏉊���                          */
/*?����???:?�Ȃ�????????????????????????????????????????????????*/
/*?============================================================?*/
void Fn_MAP_init(void)
{
  int i,j;

  /* ���H�S�̂�ǂ����邩�Ȃ�������Ȃ��ݒ�ɂ��� */
  i = 0;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 1;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 2;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 3;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 4;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 5;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 6;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 7;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 8;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 9;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 10;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 11;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 12;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 13;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 14;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 15;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }


  /* ���H�̎l����ǂ���̐ݒ�ɂ��� */
  for ( i = 0; i < MAZESIZE_X; i++ )
  {
    wall[i][0].south = WALL;            /* �� */
    wall[i][MAZESIZE_Y-1].north = WALL; /* �k */
  }

  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[0][j].west = WALL;             /* �� */
    wall[MAZESIZE_X-1][j].east = WALL;  /* �� */
  }
   
  /* �X�^�[�g�n�_�̉E����ǂ���̐ݒ�ɂ��� */
  wall[0][0].east = wall[1][0].west = WALL;
  
  /* ���Ԉʒu���W��(0,0)�ɏ����� */
  mypos.x = mypos.y = 0;

  /* ���ԕ��p��k�ɏ����� */
  mypos.dir = north;  

}


/*?============================================================?*/
/*?�֐���?:?Fn_MAP_outputWall      ?????????????????????????????*/
/*??????????�Ǐ��o��                                          */
/*?����???:?sta_wall[][MAZESIZE_Y]??????????????????????????????*/
/*?�߂�l?:?�Ȃ�????????????????????????????????????????????????*/
/*?�T�v???:?�Ǐ��o��                                          */
/*?����???:?�Ȃ�????????????????????????????????????????????????*/
/*?============================================================?*/
void Fn_MAP_outputWall(t_wall sta_wall[][MAZESIZE_Y])
{
  int i,j;

  i = 0;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 1;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 2;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 3;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 4;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 5;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 6;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 7;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 8;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 9;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 10;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 11;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 12;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 13;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 14;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 15;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }

}


/*?============================================================?*/
/*?�֐���?:?Fn_MAP_updateWall      ?????????????????????????????*/
/*??????????�Ǐ��X�V                                          */
/*?����???:?�Ȃ�????????????????????????????????????????????????*/
/*?�߂�l?:?�Ȃ�????????????????????????????????????????????????*/
/*?�T�v???:?�Ǐ��X�V                                          */
/*?����???:?�Ȃ�????????????????????????????????????????????????*/
/*?============================================================?*/
void Fn_MAP_updateWall(void)
{
  int x,y;
  unsigned char n_write,s_write,e_write,w_write;

  if (mypos.dir == north) {                        /* �k�������Ă��鎞 */
     if (wallinfo.wall_f.bl_wall_with ==1) {
	     n_write = 1;
     }else{
	     n_write = 0;
     }

     if (wallinfo.wall_r.bl_wall_with ==1) {
	     e_write = 1;
     }else{
	     e_write = 0;
     }

     if (wallinfo.wall_l.bl_wall_with ==1) {
	     w_write = 1;
     }else{
	     w_write = 0;
     }

     s_write = NOWALL;                             /* ���͕K���ǂ��Ȃ� */
  }
  
  if (mypos.dir == east) {                        /* ���������Ă��鎞 */
     if (wallinfo.wall_f.bl_wall_with ==1) {
	     e_write = 1;
     }else{
	     e_write = 0;
     }

     if (wallinfo.wall_r.bl_wall_with ==1) {
	     s_write = 1;
     }else{
	     s_write = 0;
     }

     if (wallinfo.wall_l.bl_wall_with ==1) {
	     n_write = 1;
     }else{
	     n_write = 0;
     }

     w_write = NOWALL;                             /* ���͕K���ǂ��Ȃ� */
  }
  
  if (mypos.dir == south) {                        /* ��������Ă��鎞 */
     if (wallinfo.wall_f.bl_wall_with ==1) {
	     s_write = 1;
     }else{
	     s_write = 0;
     }

     if (wallinfo.wall_r.bl_wall_with ==1) {
	     w_write = 1;
     }else{
	     w_write = 0;
     }

     if (wallinfo.wall_l.bl_wall_with ==1) {
	     e_write = 1;
     }else{
	     e_write = 0;
     }

     n_write = NOWALL;                             /* ���͕K���ǂ��Ȃ� */
  }

  if (mypos.dir == west) {                        /* ���������Ă��鎞 */
     if (wallinfo.wall_f.bl_wall_with ==1) {
	     w_write = 1;
     }else{
	     w_write = 0;
     }

     if (wallinfo.wall_r.bl_wall_with ==1) {
	     n_write = 1;
     }else{
	     n_write = 0;
     }

     if (wallinfo.wall_l.bl_wall_with ==1) {
	     s_write = 1;
     }else{
	     s_write = 0;
     }

     e_write = NOWALL;                             /* ���͕K���ǂ��Ȃ� */
  }

  

  /* ���Ԉʒu�̕Ǐ����X�V */
  x = mypos.x;
  y = mypos.y;

  wall[x][y].north = n_write;
  wall[x][y].south = s_write;
  wall[x][y].east  = e_write;
  wall[x][y].west  = w_write;

  /* ���Α����猩���Ǐ����X�V */
  if(y < MAZESIZE_Y-1)
  {
    wall[x][y+1].south = n_write;
  }

  if(x < MAZESIZE_X-1)
  {
    wall[x+1][y].west = e_write;
  }

  if(y > 0)
  {
    wall[x][y-1].north = s_write;
  }

  if(x > 0)
  {
    wall[x-1][y].east = w_write;
  }

}



/*?============================================================?*/
/*?�֐���?:?Fn_MAP_outputPosition???????????????????????  ??????*/
/*??????????���Ԉʒu���o��                                    */
/*?����???:?pst_mypos???????????????????????????????????????????*/
/*?�߂�l?:?�Ȃ�????????????????????????????????????????????????*/
/*?�T�v???:?���Ԉʒu���o��                                    */
/*?����???:?�Ȃ�????????????????????????????????????????????????*/
/*?============================================================?*/
void Fn_MAP_outputPosition(t_position *pst_mypos)
{
  pst_mypos->x = mypos.x;
  pst_mypos->y = mypos.y;
  pst_mypos->dir = mypos.dir;

}


/*?============================================================?*/
/*?�֐���?:?Fn_MAP_updatePosition??????????  ???????????????????*/
/*??????????���Ԉʒu���X�V                                    */
/*?����???:?�Ȃ�????????????????????????????????????????????????*/
/*?�߂�l?:?�Ȃ�????????????????????????????????????????????????*/
/*?�T�v???:?���Ԉʒu���X�V                                    */
/*?����???:?�Ȃ�????????????????????????????????????????????????*/
/*?============================================================?*/
void Fn_MAP_updatePosition(void)
{
  /* ���Ɍ������������L�^����ϐ� */
  t_direction glob_nextdir;

  /* ���ɍs��������߂�l�Ƃ���֐� */
  /*get_nextdir(&glob_nextdir);*/

  /* �������X�V */
  mypos.dir = glob_nextdir;

  if (mypos.dir == north) {
	  mypos.y++;
  }
  
  if (mypos.dir == east) {
	  mypos.x++;
  }

  if (mypos.dir == south) {
	  mypos.y--;
  }

  if (mypos.dir == west) {
	  mypos.x--;
  }
}

