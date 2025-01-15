// Copyright 2017-2020 Crytek GmbH / Crytek Group. All rights reserved.
#pragma once

#include <DefaultComponents/Cameras/CameraComponent.h>
#include <DefaultComponents/Input/InputComponent.h>
#include <DefaultComponents/Physics/CharacterControllerComponent.h>
#include <DefaultComponents/Geometry/AdvancedAnimationComponent.h>


class CPlayerComponent final : public IEntityComponent
{
	
public:
	CPlayerComponent() = default;
	virtual ~CPlayerComponent() = default;

	virtual void Initialize() override;

	virtual Cry::Entity::EventFlags GetEventMask() const override;
	virtual void ProcessEvent(const SEntityEvent& event) override;

	static void ReflectType(Schematyc::CTypeDesc<CPlayerComponent>& desc)
	{
		desc.SetGUID("{63F4C0C6-32AF-4ACB-8FB0-57D45DD14725}"_cry_guid);
		desc.AddMember(&CPlayerComponent::m_movementSpeed, 'pms', "playermovespeed", "Player Movement Speed", "Sets the Player Move Speed", ZERO);
		desc.AddMember(&CPlayerComponent::m_rotationSpeed, 'prs', "playerrotationspeed", "Player Rotation Speed", "Sets the speed of the players rotation", ZERO);
		desc.AddMember(&CPlayerComponent::m_cameraDefaultPos, 'cdp', "cameradefaultpos", "Camera Default Position", "Sets camera default position",ZERO);
		desc.AddMember(&CPlayerComponent::m_rotationLimitsMinPitch, 'cpm', "camerapitchmin", "Camera Pitch Min", "Sets Minimum rotation value for camera pitch", ZERO);
		desc.AddMember(&CPlayerComponent::m_rotationLimitsMaxPitch, 'cpx', "camerapitchmax", "Camera Pitch Max", "Sets Maximum rotation value for camera pitch", ZERO);
		desc.AddMember(&CPlayerComponent::m_jumpheight, 'pjh', "playerjumpheight", "Player Jump Height", "Sets the Player Jump Height", ZERO);
	}

private:
	Cry::DefaultComponents::CCameraComponent* m_pCameraComponent;
	Cry::DefaultComponents::CInputComponent* m_pInputComponent;
	Cry::DefaultComponents::CCharacterControllerComponent* m_pCharacterController;
	Cry::DefaultComponents::CAdvancedAnimationComponent* m_pAdvancedAnimationComponent;


	float m_movementSpeed = 3.f;
	Vec2 m_movementDelta = ZERO;

	float m_rotationSpeed = 0.002f;
	Vec2 m_mouseDeltaRotation;
	Quat m_lookOrientation;
	Vec3 m_cameraDefaultPos = {0.f,0.f,1.75f};

	float m_rotationLimitsMinPitch = -0.85f;
	float m_rotationLimitsMaxPitch = 1.5f;

	float m_jumpheight = 3.f;

	void InitInputs();

	void Movement();
	void Camera();
	void Jump();

	void Reset();
};