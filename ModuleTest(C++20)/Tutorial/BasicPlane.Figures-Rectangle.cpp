// �w���W���[���̎��� �t�@�C���x
module;
// global module fragment area. Put #include firectives here
// �O���[�o�� ���W���[�� �t���O�����g �ƌĂ΂�郂�W���[���̓��ʂȗ̈�𓱓�
// windows.h��unistd.h(Linux�̏ꍇ)�Ȃǂ̃w�b�_�[�t�@�C�����C���N���[�h����̂ɓK�����ꏊ

// �����ō\�����郂�W���[�������t�@�C���ł́A���C�u�������C���N���[�h���Ȃ��B
// �����̈ꕔ�Ƃ��ĕK�v�Ȃ����߁B�������A�K�v�ȏꍇ�͂��̗̈��#include�f�B���e�B�u��u���B
// (�������������̂��F#include����Ƃ���module;�̉��ɏ����Ă˂��Ă��Ƃł��B)

module BasicPlane.Figures:Rectangle;

int area(const Rectangle& _r) { return width(_r) * height(_r); }
int height(const Rectangle& _r) { return _r.ul.y - _r.lr.y; }
int width(const Rectangle& _r) { return _r.lr.x - _r.ul.x; }