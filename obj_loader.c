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

  VertexVec   vertices  = {0};
  TexCoordVec uv_coords = {0};
  NormalVec   normals   = {0};
  FaceVec     faces     = {0};
  int const   line_size = 256;
  char        line_buf[line_size];
  // # denotes comments, line starting with o can be discarded
  char  *c;
  float *f1, *f2, *f3, *f4;
  int   *i1, *i2, *i3;
  while (1)
  {
    // Parse vertices, w defaults to 1.0
    // 	v x y z w
    if (!fgets(line_buf, line_size, f_ptr)) goto error;

    int n = sscanf(line_buf, "%s %f %f %f %f", c, f1, f2, f3, f4);
    if (n < 1) goto error;
    if (strcmp(c, "o") && strcmp(c, "#")) continue;
    if (strcmp(c, "vt")) break;
    if (n < 3) goto error;
    Vertex v = {0};
    v.x      = *f1;
    v.y      = *f2;
    v.z      = *f3;
    if (n == 3)
      v.w = 1.0;
    else if (n == 4)
      v.w = *f4;
    else
      goto error;

    append(vertices, v);
    // TODO: test print v
  }
  // Parse tex coords, v, w defaults to 0
  {
    // 	vt u v w
  }
  // Parse normals
  {
  }
  // 	vn x y z
  // Skip parameter space vertices (for now)
  {
    //	vp ...
  }
  // Parse faces
  {
    //  f v_i/vt_i/vn_i
  }
error:
  printf("Something fucked up\n");

  // if (feof(f_ptr)) printf("End of file reached");
}
