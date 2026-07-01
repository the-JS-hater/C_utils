#include "d_array.h"
#include "stdio.h"

typedef struct {
  float x, y, z, w;
} Vertex;

typedef struct {
  Vertex *items;
  size_t  capacity, size;
} VertexVec;

typedef struct {
  float u, v, w;
} TexCoord;

typedef struct {
  TexCoord *items;
  size_t    capacity, size;
} TexCoordVec;

typedef struct {
  float x, y, z;
} Normal;

typedef struct {
  Normal *items;
  size_t  capacity, size;
} NormalVec;

typedef struct {
  int v_idx, vt_idx, vn_idx;
} FaceElement;

typedef struct {
  FaceElement *items;
  size_t       capacity, size;
} FaceVec;

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("too few args\n");
    return 1;
  }
  char const *file_name = argv[1];
  printf("Filename: %s\n", file_name);

  FILE *f_ptr = fopen(file_name, "r");
  if (!f_ptr)
  {
    printf("failed to open file\n");
    return -1;
  }

  // # denotes comments, line starting with o can be discarded

  // Parse vertices, w defaults to 1.0
  // 	v x y z w
  // Parse tex coords, v, w defaults to 0
  // 	vt u v w
  // Parse normals
  // 	vn x y z
  // Skip parameter space vertices (for now)
  //	vp ...
  // Parse faces
  //  f v_i/vt_i/vn_i
}
