/* This is my cover letter. It runs. */

/*
 * According to my mum, my most overused first word was "why." It followed
 * me into code, and it's what brought me to Signaloid. So I wrote my
 * application the only honest way I could: as a probabilistic program —
 * confidence and uncertainty both shown, neither one hidden.
 *
 * In that same spirit: the words and the why are mine; I paired with an AI
 * to translate them into working Signaloid code.
 */

#include <uxhw.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
	/* ACT 1 — the "why" loop. I start knowing almost nothing: a wide curve
	 * near zero, where the spread is bigger than the mean. */
	double understanding = UxHwDoubleGaussDist(0.1, 0.4);

	/* I don't even know how deep this field goes, so "fully understanding it"
	 * is a range up here, not a fixed point. */
	double full_grasp = UxHwDoubleUniformDist(0.9, 1.0);

	/* Each good question closes about a quarter of the gap. */
	double learning_rate = 0.25;

	const char *questions[5] = {
		"What on earth is all of this? Something to do with statistics and probability, I think.",
		"What's a Monte Carlo method? ...ah — it's a simulation, and an expensive one.",
		"So how does Signaloid replace it? With a unique processor architecture, apparently.",
		"A chip that computes not just the numbers, but the probability wrapped around them — huh.",
		"Do I fully get it yet? Honestly, no — but it runs on a cloud platform, and that part I know cold."
	};

	printf("ACT 1 — learning by asking why\n\n");

	for (int q = 0; q < 5; q++)
	{
		/* A question doesn't overwrite what I knew — it nudges it toward
		 * what's true and tightens the spread. The distribution does the rest. */
		understanding = understanding * (1.0 - learning_rate)
		              + full_grasp * learning_rate;

		printf("Question %d: %s\n", q + 1, questions[q]);
		printf("    understanding now centers near %.2f, and the curve keeps narrowing\n\n",
		       UxHwDoubleNthMoment(understanding, 1));
	}

	/* Five whys in, I understand far more, but the curve still has width — and
	 * probably always will. The work I love most is making hard things feel
	 * learnable: a visual language for the difficult. (Fourteen years in film
	 * and TV before code; the instinct for how things should look stayed.) */
	printf("After five whys, understanding centers near %.2f — converging, never quite 1.0.\n",
	       UxHwDoubleNthMoment(understanding, 1));
	printf("The leftover width isn't a weakness. It's the room I keep learning in.\n\n");

	/* I've spent real time in the platform — clean foundation, room to grow
	 * (nav depth, spacing, dark mode), Vue + Vuetify underneath: home turf. */

	/* ACT 2 — the part I'm sure about: things I've lived, so these curves are
	 * tall and narrow. */

	/* Four years owning a cloud SaaS frontend (five-plus in the craft):
	 * complexity without flinching, knowing where data flows quietly break. */
	double cloud_saas_experience = UxHwDoubleGaussDist(0.90, 0.05);

	/* Grew four devs into stronger engineers; took one from the fundamentals
	 * to owning a whole feature alone. */
	double mentorship_track_record = UxHwDoubleGaussDist(0.88, 0.06);

	/* Empathy, honesty, listening — the narrowest curve, because it's
	 * non-negotiable. Good communication is a clean signal: less noise. */
	double values_alignment = UxHwDoubleGaussDist(0.94, 0.02);

	/* The honest one: how well I know your domain today — the variable from
	 * Act 1, trending right but still uncertain. */
	double domain_understanding = understanding;

	/* Combine them, weighted — leaning on what matters most and what I'm
	 * surest of, while still giving the moving target real weight. */
	double probability_of_good_hire =
	      0.30 * values_alignment
	    + 0.25 * cloud_saas_experience
	    + 0.20 * mentorship_track_record
	    + 0.25 * domain_understanding;

	printf("ACT 2 — putting it together\n\n");
	printf("    cloud SaaS ownership   ~ %.2f\n", UxHwDoubleNthMoment(cloud_saas_experience, 1));
	printf("    mentorship             ~ %.2f\n", UxHwDoubleNthMoment(mentorship_track_record, 1));
	printf("    values alignment       ~ %.2f\n", UxHwDoubleNthMoment(values_alignment, 1));
	printf("    domain understanding   ~ %.2f  (the one still converging)\n",
	       UxHwDoubleNthMoment(domain_understanding, 1));
	printf("\n");

	double mean_good_hire = UxHwDoubleNthMoment(probability_of_good_hire, 1);

	printf("Mean probability of good hire: %.2f. The uncertainty is the honest part. — Julia\n",
	       mean_good_hire);

	return 0;
}
