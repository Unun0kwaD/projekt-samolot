
#include <lights.h>

void lightdir(Shader &object_shader)
	{
	object_shader.use();

	// object_shader.setVec3("dirLight.position", glm::vec3(400.0f, 200.0f, 200.0f));
	object_shader.setVec3("dirLight.direction", 0.2f, 1.0f, 0.3f);
	object_shader.setVec3("dirLight.ambient", glm::vec3(0.3f, 0.3f, 0.3f));
	object_shader.setVec3("dirLight.diffuse", 1.0f, 1.0f, 0.8f);
	object_shader.setVec3("dirLight.specular", 1.0f, 1.0f, 0.8f);


	object_shader.setFloat("material.shininess", 32.0f); 
	}

void RunwayLight1(Shader &object_shader, glm::vec3 start, glm::vec3 end)
{
	
	object_shader.setVec3("pointLights[0].position", start + glm::vec3(5.2f, 0.24f, 0.0f));
	object_shader.setVec3("pointLights[0].ambient", 0.8f, 0.1f, 0.1f);
	object_shader.setVec3("pointLights[0].diffuse", 1.0f, 0.0f, 0.0f);
	object_shader.setVec3("pointLights[0].specular", 1.0f, 0.0f, 0.0f);
	object_shader.setFloat("pointLights[0].constant", 1.0f);
	object_shader.setFloat("pointLights[0].linear", 0.22);
	object_shader.setFloat("pointLights[0].quadratic", 0.20);

	object_shader.setVec3("pointLights[1].position", start + glm::vec3(-5.2f, 0.24f, 0.0f));
	object_shader.setVec3("pointLights[1].ambient", 0.8f, 0.1f, 0.1f);
	object_shader.setVec3("pointLights[1].diffuse", 1.0f, 0.0f, 0.0f);
	object_shader.setVec3("pointLights[1].specular", 1.0f, 0.0f, 0.0f);
	object_shader.setFloat("pointLights[1].constant", 1.0f);
	object_shader.setFloat("pointLights[1].linear", 0.22);
	object_shader.setFloat("pointLights[1].quadratic", 0.20);

	object_shader.setVec3("pointLights[2].position", end + glm::vec3(5.2f, 0.24f, 0.0f));
	object_shader.setVec3("pointLights[2].ambient", 0.8f, 0.1f, 0.1f);
	object_shader.setVec3("pointLights[2].diffuse", 1.0f, 0.0f, 0.0f);
	object_shader.setVec3("pointLights[2].specular", 1.0f, 0.0f, 0.0f);
	object_shader.setFloat("pointLights[2].constant", 1.0f);
	object_shader.setFloat("pointLights[2].linear", 0.22);
	object_shader.setFloat("pointLights[2].quadratic", 0.20);

	object_shader.setVec3("pointLights[3].position", end + glm::vec3(-5.2f, 0.24f, 0.0f));
	object_shader.setVec3("pointLights[3].ambient", 0.8f, 0.1f, 0.1f);
	object_shader.setVec3("pointLights[3].diffuse", 1.0f, 0.0f, 0.0f);
	object_shader.setVec3("pointLights[3].specular", 1.0f, 0.0f, 0.0f);
	object_shader.setFloat("pointLights[3].constant", 1.0f);
	object_shader.setFloat("pointLights[3].linear", 0.22);
	object_shader.setFloat("pointLights[3].quadratic", 0.20);
}


void RunwayLight2(Shader &object_shader, glm::vec3 start, glm::vec3 end)
{
	
	object_shader.setVec3("pointLights[4].position", start + glm::vec3(5.2f, 0.24f, 0.0f));
	object_shader.setVec3("pointLights[4].ambient", 0.8f, 0.1f, 0.1f);
	object_shader.setVec3("pointLights[4].diffuse", 1.0f, 0.0f, 0.0f);
	object_shader.setVec3("pointLights[4].specular", 1.0f, 0.0f, 0.0f);
	object_shader.setFloat("pointLights[4].constant", 1.0f);
	object_shader.setFloat("pointLights[4].linear", 0.22);
	object_shader.setFloat("pointLights[4].quadratic", 0.20);

	object_shader.setVec3("pointLights[5].position", start + glm::vec3(-5.2f, 0.24f, 0.0f));
	object_shader.setVec3("pointLights[5].ambient", 0.8f, 0.1f, 0.1f);
	object_shader.setVec3("pointLights[5].diffuse", 1.0f, 0.0f, 0.0f);
	object_shader.setVec3("pointLights[5].specular", 1.0f, 0.0f, 0.0f);
	object_shader.setFloat("pointLights[5].constant", 1.0f);
	object_shader.setFloat("pointLights[5].linear", 0.22);
	object_shader.setFloat("pointLights[5].quadratic", 0.20);

	object_shader.setVec3("pointLights[6].position", end + glm::vec3(5.2f, 0.24f, 0.0f));
	object_shader.setVec3("pointLights[6].ambient", 0.8f, 0.1f, 0.1f);
	object_shader.setVec3("pointLights[6].diffuse", 1.0f, 0.0f, 0.0f);
	object_shader.setVec3("pointLights[6].specular", 1.0f, 0.0f, 0.0f);
	object_shader.setFloat("pointLights[6].constant", 1.0f);
	object_shader.setFloat("pointLights[6].linear", 0.22);
	object_shader.setFloat("pointLights[6].quadratic", 0.20);

	object_shader.setVec3("pointLights[7].position", end + glm::vec3(-5.2f, 0.24f, 0.0f));
	object_shader.setVec3("pointLights[7].ambient", 0.8f, 0.1f, 0.1f);
	object_shader.setVec3("pointLights[7].diffuse", 1.0f, 0.0f, 0.0f);
	object_shader.setVec3("pointLights[7].specular", 1.0f, 0.0f, 0.0f);
	object_shader.setFloat("pointLights[7].constant", 1.0f);
	object_shader.setFloat("pointLights[7].linear", 0.22);
	object_shader.setFloat("pointLights[7].quadratic", 0.20);
}