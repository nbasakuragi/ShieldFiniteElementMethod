#include "FemController.h"
#include "common.h"

using namespace Rendering;

namespace Controller
{ 
	FemController::FemController() : AbstractController("Fem GEM CPU")
	{
		d_simulation = new Simulation();
	}
	
	
	FemController::~FemController()
	{
		delete d_shader;
		//delete d_model;
	}
	
	
	int FemController::MeshLoad()
	{
	
		LOGI("Load meshes");
		if (!d_simulation->simulation_load_fem_mesh(RAPTOR_NETGEN_MESH))
		{
			//return 1;
		}
		/*	for (unsigned int a = 0; a < render_filenames.size(); ++a)
		d_simulation->simulation_load_render_mesh(render_filenames[a].c_str());*/
		/*	if (reorder)
		d_simulation->simulation_reorder_fem_mesh();*/
	
		LOGI("Init simulation");
		if (!d_simulation->simulation_init())
			return 1;
		return 0;
	}
	 
	
	void FemController::InitParams()
	{
		this->d_camera->Position = glm::vec3(0.0f,5.0f,-30.0f);
		d_camera->CameraType = FREE_FLY;
		d_camera->MovementSpeed = 0.5f;
		d_camera->SetTarget(glm::vec3(0,0,0)); 

		//UserKeyboardCallback = std::bind(&FemController::Read_Input,this); 
		d_model = new Model(RAPTOR_MODEL);

		vector<Mesh>* meshes = d_model->GetMeshes( );

		d_simulation->SetMeshes(meshes);
		if (!d_simulation->simulation_preload())
		{
			LOGE("Error starting the simulation...");
		}	

		if (MeshLoad())
		{
			LOGE("Error initializing the meshes...");

		} 

		vector<string> v_shader;
		v_shader.push_back("vertex.vert");
		v_shader.push_back("common.vert");
		vector<string> f_shader;
		f_shader.push_back("fragment.frag");
		f_shader.push_back("common.frag");
		d_shader = new Shader(v_shader,f_shader);
	}

	void FemController::Draw()
	{
		glm::mat4 projection_view;
	
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		d_simulation->simulation_animate();
	
		d_simulation->simulation_mapping(); // make sure the surfaces are up-to-date
	
		d_projection_matrix = glm::perspective(d_camera->Zoom, VIEWPORT_RATIO, 0.1f, 1000.0f);  
	
		d_camera->MoveCamera();
	
		d_view_matrix = d_camera->GetViewMatrix(); 
	
		projection_view = d_projection_matrix * d_view_matrix;  
	
		d_shader->Use();
		d_shader->SetUniform("mvp", d_projection_matrix * d_view_matrix * d_model->GetModelMatrix());
		d_shader->SetUniform("mv",   d_view_matrix * d_model->GetModelMatrix());
		d_shader->SetUniform("model_matrix", d_model->GetModelMatrix());
		d_shader->SetUniform("model_transpose_inverse",  glm::transpose(glm::inverse(d_model->GetModelMatrix())));  
	
		d_model->Draw(*d_shader);
	
		//glutSwapBuffers();
	}
	 
	 
}