#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <vector>

namespace voxel_engine {

class VertexArrayObject {
public:
	class Loader {
	public:
		Loader(VertexArrayObject &vao);
		~Loader();

		void store(GLuint const attr, std::vector<glm::vec2> const &data, GLuint div = 0);
		void store(GLuint const attr, std::vector<glm::vec3> const &data, GLuint div = 0);
		void store(GLuint const attr, std::vector<glm::vec4> const &data, GLuint div = 0);
		void store(std::vector<GLuint> const &data);

	private:
		VertexArrayObject &vao_;
	};

	VertexArrayObject();
	VertexArrayObject(VertexArrayObject const&) = delete;

	~VertexArrayObject();

	void draw(GLenum mode = GL_TRIANGLES);
	void drawInstanced(GLenum mode, GLsizei count);

private:
	GLuint getBuffer();

	GLuint id_;
	GLuint indices_ {0};
	std::vector<GLuint> buffers_;
};

} // namespace voxel_engine