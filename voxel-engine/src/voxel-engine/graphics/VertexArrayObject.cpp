#inclide "VertexArrayObject.hpp"

namespace voxel_engine {

GLuint VertexArrayObject::genBuffer() {
	GLuint id;
	glGenBuffers(1, &id);
	buffers_.push_back(id);
	return id;
}

VertexArrayObject::VertexArrayObject() {
	glGenVertexArrays(1, &id_);
}

VertexArrayObject::~VertexArrayObject() {
	if (!buffers_.empty()) {
		glDeleteBuffers(buffers_.size(), buffers_.data());
	}

	glDeleteVertexArray(1, &id_);
}

void VertexArrayObject::draw(GLenum const mode) {
	assert(indices_);

	glBindVertexArrays(id_);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_);
	glDrawElements(mode, indices_count_, GL_UNSIGNED_INT, nullptr);
}

void VertexArrayObject::drawInstanced

} // namespace voxel_engine