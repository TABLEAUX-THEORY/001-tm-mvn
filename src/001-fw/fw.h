#ifndef FW
#define FW
#include <stdint.h>
#include <stdbool.h>

typedef struct {
	int width;
	int height;
	uint32_t* pixels;  // Raw pixel data
}Image;

typedef struct{
	int temp;
// TODO
}Model;

typedef struct{
	int temp;
// TODO
}Sound;

typedef struct{
	int temp;
// TODO
}AudioStream;

typedef struct{
	float x,y,z;
	float qa,qb,qc,qd;
	float scale; //FOV or height depending on projection type.
	float near_plane;
	float far_plane;
	bool orthographic;
}Camera;

typedef struct{
	const char* text;
	const char* cursor;
}Script;

//Main.
void fw_init(const char* window_name);
void fw_close(); //TODO
void begin_frame();
void end_frame();
bool is_termination_requested();
void set_windowed(); //TODO
void set_fullscreen(); //TODO

//Script Parsing.
Script* load_script(const char** path); //TODO
char* get_line(Script* script); //TODO: This includes the "if" parsing.

//Data.
char* get_dat_val(const char* section, const char* key); //TODO
void set_dat_val(const char* section, const char* key, const char* value); //TODO
void load_dat(); //TODO
void save_dat(); //TODO
void save_dat_only(const char** sections); //TODO
void save_dat_except(const char** sections); //TODO
void reset_dat(); //TODO
void reset__dat_only(const char** sections); //TODO
void reset_dat_except(const char* sections); //TODO

// Input.
bool is_left_down(); //TODO
bool is_left_pressed(); //TODO
bool is_left_released(); //TODO
bool is_right_down(); //TODO
bool is_right_pressed(); //TODO
bool is_right_released(); //TODO
bool is_up_down(); //TODO
bool is_up_pressed(); //TODO
bool is_up_released(); //TODO
bool is_down_down(); //TODO
bool is_down_pressed(); //TODO
bool is_down_released(); //TODO
bool is_action_down(); //TODO
bool is_action_pressed(); //TODO
bool is_action_released(); //TODO

//Resource Loading.
Image* create_image(int width, int height);
Image* load_image(const char* path);
Model* load_model(const char* path); //TODO
Sound* load_sound(const char* path); //TODO
AudioStream* load_audio_stream(const char* path); //TODO
void unload_image(Image image); //TODO
void unload_model(Model* model); //TODO
void unload_sound(Sound* sound); //TODO
void unload_audio_stream(AudioStream* stream); //TODO

//Sound.
void play_sound(Sound sound, float volume, float pan); //TODO
void pause_sound(Sound* sound); //TODO
void resume_sound(Sound* sound); //TODO
void stop_sound(Sound* sound); //TODO

//Audio stream.
void play_audio_stream(AudioStream stream, float volume, float pan, bool looping); //TODO
void pause_audio_stream(AudioStream* stream); //TODO
void resume_audio_stream(AudioStream* stream); //TODO
void stop_audio_stream(AudioStream stream); //TODO

//Drawing 2D.
uint32_t get_pixel(int x, int y);
void draw_pixel(int x, int y, uint32_t color);
void draw_line(int x0, int y0, int x1, int y1, uint32_t color_0, uint32_t color_1);
void draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, uint32_t color);
void draw_rectangle(int x0, int y0, int x1, int y1, uint32_t color); //TODO
void draw_rectangle_lines(int x0, int y0, int x1, int y1, uint32_t color); //TODO
void draw_image(Image* image, int x, int y);
void draw_image_region(Image* image, int x, int y, int rec_x0, int rec_y0, int rec_x1, int rec_y1);

//Drawing 3D,
void set_active_camera(Camera* camera); //TODO
void set_model_frame(Model model, int frame); //TODO
void draw_line_3d(int x0, int y0, int z0, int x1, int y1, int z1, uint32_t color); //TODO
void draw_triangle_3d(int x0, int y0, int z0, int x1, int y1, int z1, int x2, int y2, int z2, uint32_t color); //TODO
void draw_model(Model model, int x, int y, int z, int r0, int qa, int qb, int qc, int qd); //TODO

//Drawing text.
void get_text_width(const char* text, int size); //TODO
void draw_char_6(int x, int y, const char c, uint32_t color);
void draw_char_8(int x, int y, const char c, uint32_t color);
void draw_char_16(int x, int y, const char c, uint32_t color);
void draw_string_6(int x, int y, const char c, uint32_t color); //TODO
void draw_string_8(int x, int y, const char* text, uint32_t color); //TODO
void draw_string_16(int x, int y, const char* text, uint32_t color); //TODO

//Advanced drawing.
void begin_draw_target(Image* target); //TODO
void end_draw_target(); //TODO

#endif
