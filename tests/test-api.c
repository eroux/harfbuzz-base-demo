// wildly adapted from harfbuzz-tutorial (although almost no common code)

#include <stdlib.h>
#include <stdio.h>
#include <hb.h>
#include <hb-ft.h>
#include <hb-ot.h>

#define FONT_SIZE 36

int
main(int argc, char **argv)
{
  const char *fontfile;

  if (argc < 2)
  {
    fprintf (stderr, "usage: test-api font-file.ttf\n");
    exit (1);
  }

  fontfile = argv[1];

  /* Initialize FreeType and create FreeType font face. */
  FT_Library ft_library;
  FT_Face ft_face;
  FT_Error ft_error;

  if ((ft_error = FT_Init_FreeType (&ft_library)))
    abort();
  if ((ft_error = FT_New_Face (ft_library, fontfile, 0, &ft_face)))
    abort();
  if ((ft_error = FT_Set_Char_Size (ft_face, FONT_SIZE*64, FONT_SIZE*64, 0, 0)))
    abort();

  hb_face_t *hb_face = hb_ft_face_create_referenced (ft_face);
  hb_bool_t has_base = hb_ot_base_has_data(hb_face);
  if (has_base) {
    fprintf (stdout, "this font has a BASE table\n");
  } else {
    fprintf (stdout, "this font does not have a BASE table\n");
  }

  FT_Done_Face (ft_face);
  FT_Done_FreeType (ft_library);

  return 0;
}
