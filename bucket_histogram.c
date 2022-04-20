#include "bucket_histogram.h"

void parse_bucket_histogram(FILE *file, struct bucket_BGR *buckets, int n_pixles) {
  struct pixel_BGR pixel;

  for (int i = 0; i < n_pixles; i++) {
    fread(&pixel, sizeof(struct pixel_BGR), 1, file);
    buckets[pixel.blue / 16].nBlue++;
    buckets[pixel.green / 16].nGreen++;
    buckets[pixel.red / 16].nRed++;
  }
}

void print_bucket_histogram(struct bucket_BGR buckets[], int total_pixels) {
  int offset       = 16;
  int bucket_start = 0;
  int bucket_end   = 15;
  printf("HISTOGRAM:\n");

  printf("\t Blue: \n");
  for (int i = 0; i < offset; i++) {
    printf("\t\t%d-%d: %.2f%%\n", bucket_start + i * offset, bucket_end + i * offset, ((float)buckets[i].nBlue * 100) / total_pixels);
  }
  printf("\t Green: \n");
  for (int i = 0; i < offset; i++) {
    printf("\t\t%d-%d: %.2f%%\n", bucket_start + i * offset, bucket_end + i * offset, ((float)buckets[i].nGreen * 100) / total_pixels);
  }
  printf("\t Red: \n");
  for (int i = 0; i < offset; i++) {
    printf("\t\t%d-%d: %.2f%%\n", bucket_start + i * offset, bucket_end + i * offset, ((float)buckets[i].nRed * 100) / total_pixels);
  }
}