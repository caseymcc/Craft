#ifndef _chunk_h_
#define _chunk_h_

#include <GLFW/glfw3.h>

#define CHUNK_SIZE 32

#define BELOW 0x01
#define ABOVE 0x02
#define LEFT 0x04
#define RIGHT 0x08
#define FRONT 0x10
#define BACK 0x20

typedef struct {
    char blocks[CHUNK_SIZE*CHUNK_SIZE*CHUNK_SIZE];
    int p;
    int q;
    int k;
    int faces;
    int dirty;
    char opaque_neighbours;
    GLuint buffer;
} Chunk;

char chunk_get(Chunk *chunk, int x, int y, int z);
void chunk_set(Chunk *chunk, int x, int y, int z, int w);

#define CHUNK_FOR_EACH(blocks, ex, ey, ez, ew) \
  for(int ex = 0; ex < CHUNK_SIZE; ex++) { \
    for(int ey = 0; ey < CHUNK_SIZE; ey++) { \
      for(int ez = 0; ez < CHUNK_SIZE; ez++) { \
        int ew = blocks[ex+ey*CHUNK_SIZE+ez*CHUNK_SIZE*CHUNK_SIZE];

#define END_CHUNK_FOR_EACH \
       } \
     } \
   }

#define CHUNK_FOR_EACH_YZ(blocks, x, ex, ey, ez, ew)     \
  for(int ey = 0; ey < CHUNK_SIZE; ey++) { \
    for(int ez = 0; ez < CHUNK_SIZE; ez++) { \
      int ex = x; \
      int ew = blocks[ex+ey*CHUNK_SIZE+ez*CHUNK_SIZE*CHUNK_SIZE];

#define CHUNK_FOR_EACH_XY(blocks, z, ex, ey, ez, ew)     \
  for(int ex = 0; ex < CHUNK_SIZE; ex++) { \
    for(int ey = 0; ey < CHUNK_SIZE; ey++) { \
      int ez = z; \
      int ew = blocks[ex+ey*CHUNK_SIZE+ez*CHUNK_SIZE*CHUNK_SIZE];

#define CHUNK_FOR_EACH_XZ(blocks, y, ex, ey, ez, ew)     \
  for(int ex = 0; ex < CHUNK_SIZE; ex++) { \
    for(int ez = 0; ez < CHUNK_SIZE; ez++) { \
      int ey = y; \
      int ew = blocks[ex+ey*CHUNK_SIZE+ez*CHUNK_SIZE*CHUNK_SIZE];

#define END_CHUNK_FOR_EACH_2D \
     } \
   }

#define CHUNK_FOR_EACH_X(blocks, y, z, ex, ey, ez, ew)   \
  for(int ex = 0; ex < CHUNK_SIZE; ex++) { \
    int ey = y; \
    int ez = z; \
    int ew = blocks[ex+ey*CHUNK_SIZE+ez*CHUNK_SIZE*CHUNK_SIZE];

#define CHUNK_FOR_EACH_Y(blocks, x, z, ex, ey, ez, ew)   \
  for(int ey = 0; ey < CHUNK_SIZE; ey++) { \
    int ez = z; \
    int ex = x; \
    int ew = blocks[ex+ey*CHUNK_SIZE+ez*CHUNK_SIZE*CHUNK_SIZE];

#define CHUNK_FOR_EACH_Z(blocks, x, y, ex, ey, ez, ew)   \
  for(int ez = 0; ez < CHUNK_SIZE; ez++) { \
    int ex = x; \
    int ey = y; \
    int ew = blocks[ex+ey*CHUNK_SIZE+ez*CHUNK_SIZE*CHUNK_SIZE];

#define END_CHUNK_FOR_EACH_1D \
  }



#endif
