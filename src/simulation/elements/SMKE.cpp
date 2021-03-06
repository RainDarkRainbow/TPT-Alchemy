#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_SMKE PT_SMKE 57
Element_SMKE::Element_SMKE()
{
	Identifier = "DEFAULT_PT_SMKE";
	Name = "SMKE";
	Colour = PIXPACK(0x222222);
	MenuVisible = 0;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 0.9f;
	AirDrag = 0.04f * CFDS;
	AirLoss = 0.97f;
	Loss = 0.20f;
	Collision = 0.0f;
	Gravity = -0.1f;
	Diffusion = 0.00f;
	HotAir = 0.001f	* CFDS;
	Falldown = 1;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 1;

	Weight = 1;

	Temperature = R_TEMP+320.0f+273.15f;
	HeatConduct = 88;
	Description = "Smoke, created by fire.";

	Properties = TYPE_GAS|PROP_LIFE_DEC|PROP_LIFE_KILL_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 10 + O_CELS;
	LowTemperatureTransition = PT_DUST;
	HighTemperature = 625.0f;
	HighTemperatureTransition = PT_FIRE;

	Update = &Element_SMKE::update;
	Graphics = &Element_SMKE::graphics;
}

//#TPT-Directive ElementHeader Element_SMKE static int update(UPDATE_FUNC_ARGS)
int Element_SMKE::update(UPDATE_FUNC_ARGS)
{
	return Element_ETRD::craft_with(UPDATE_FUNC_SUBCALL_ARGS, PT_BIZRS, PT_MORT);
}

//#TPT-Directive ElementHeader Element_SMKE static int graphics(GRAPHICS_FUNC_ARGS)
int Element_SMKE::graphics(GRAPHICS_FUNC_ARGS)

{
	*colr = 55;
	*colg = 55;
	*colb = 55;

	*firea = 75;
	*firer = 55;
	*fireg = 55;
	*fireb = 55;

	*pixel_mode = PMODE_NONE; //Clear default, don't draw pixel
	*pixel_mode |= FIRE_BLEND;
	//Returning 1 means static, cache as we please
	return 1;
}

Element_SMKE::~Element_SMKE() {}
