void setupTim2()
{
	/* 16MHz -> 50Hz = 320000 */
	TIM2->PSC = (16 - 1);
	TIM2->ARR = (20000 - 1);//20ms
}

void setupPwm_1(void)
{
	//PB8
	/* clock gpio */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	GPIOB->MODER &= ~GPIO_MODER_MODE8_0;
	GPIOB->MODER |= GPIO_MODER_MODE8_1;

	/* pin AF 1 */
	GPIOB->AFR[1] |= GPIO_AFRH_AFRH0_0;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFRH0_1;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFRH0_2;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFRH0_3;

	/* output type push pull */
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT8_Msk;

	/* clock periphery */
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/* tim 2 setup */
	//channel als ausgang
	TIM2->CCMR1 &= ~ TIM_CCMR1_CC1S_Msk;

	/* output type (pwm 1) clear */
	TIM2->CCMR1 &= ~TIM_CCMR1_OC1M_Msk;

	/* pmw 1 mode */
	TIM2->CCMR1 &= ~TIM_CCMR1_OC1M_0;
	TIM2->CCMR1 |= TIM_CCMR1_OC1M_1;
	TIM2->CCMR1 |= TIM_CCMR1_OC1M_2;

	/* aktivieren capture compare kanal 2 +1  */
	//TIM2->CCER |= TIM_CCER_CC2E;
	TIM2->CCER |= TIM_CCER_CC1E;

	TIM2->CR1 |= TIM_CR1_CEN;

}

void setupPwm_2(void)
{
	//PB9
	/* clock gpio */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	GPIOB->MODER &= ~GPIO_MODER_MODE9_0;
	GPIOB->MODER |= GPIO_MODER_MODE9_1;

	/* pin AF 1 */
	GPIOB->AFR[1] |= GPIO_AFRH_AFRH1_0;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFRH1_1;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFRH1_2;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFRH1_3;

	/* output type push pull */
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT9_Msk;

	/* clock periphery */
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/* tim 2 setup */
	//channel als ausgang
	TIM2->CCMR1 &= ~ TIM_CCMR1_CC2S_Msk;

	/* output type (pwm 1) clear */
	TIM2->CCMR1 &= ~TIM_CCMR1_OC2M_Msk;

	/* pmw 1 mode */
	TIM2->CCMR1 &= ~TIM_CCMR1_OC2M_0;
	TIM2->CCMR1 |= TIM_CCMR1_OC2M_1;
	TIM2->CCMR1 |= TIM_CCMR1_OC2M_2;

	/* aktivieren capture compare kanal */
	TIM2->CCER |= TIM_CCER_CC2E;
}

void setupPwm_3(void)
{
	//PB10
	/* clock gpio */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	GPIOB->MODER &= ~GPIO_MODER_MODE10_0;
	GPIOB->MODER |= GPIO_MODER_MODE10_1;

	/* pin AF 1 */
	GPIOB->AFR[1] |= GPIO_AFRH_AFRH2_0;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFRH2_1;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFRH2_2;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFRH2_3;

	/* output type push pull */
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT10_Msk;

	/* clock periphery */
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/* tim 2 setup */
	//channel als ausgang
	TIM2->CCMR2 &= ~ TIM_CCMR2_CC3S_Msk;

	/* output type (pwm 1) clear */
	TIM2->CCMR2 &= ~TIM_CCMR2_OC3M_Msk;

	/* pmw 1 mode */
	TIM2->CCMR2 &= ~TIM_CCMR2_OC3M_0;
	TIM2->CCMR2 |= TIM_CCMR2_OC3M_1;
	TIM2->CCMR2 |= TIM_CCMR2_OC3M_2;

	/* aktivieren capture compare kanal */
	//TIM2->CCER |= TIM_CCER_CC2E;
	TIM2->CCER |= TIM_CCER_CC3E;
}


void setupPwm_4(void)
{
	//PB2
	/* clock gpio */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	GPIOB->MODER &= ~GPIO_MODER_MODE2_0;
	GPIOB->MODER |= GPIO_MODER_MODE2_1;

	/* pin AF 1 */
	GPIOB->AFR[0] |= GPIO_AFRL_AFRL2_0;
	GPIOB->AFR[0] &= ~GPIO_AFRL_AFRL2_1;
	GPIOB->AFR[0] &= ~GPIO_AFRL_AFRL2_2;
	GPIOB->AFR[0] &= ~GPIO_AFRL_AFRL2_3;

	/* output type push pull */
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT2_Msk;

	/* clock periphery */
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/* tim 2 setup */
	//channel als ausgang
	TIM2->CCMR2 &= ~ TIM_CCMR2_CC4S_Msk;

	/* output type (pwm 1) clear */
	TIM2->CCMR2 &= ~TIM_CCMR2_OC4M_Msk;

	/* pmw 1 mode */
	TIM2->CCMR2 &= ~TIM_CCMR2_OC4M_0;
	TIM2->CCMR2 |= TIM_CCMR2_OC4M_1;
	TIM2->CCMR2 |= TIM_CCMR2_OC4M_2;

	/* aktivieren capture compare kanal */
	TIM2->CCER |= TIM_CCER_CC4E;
}







//######################################################################
int main()
{
	setupPwm_1();
	setupPwm_2();
	setupPwm_3();
	setupPwm_4();

	setupTim2();

	TIM2->CCR1 = 1500;
	TIM2->CCR2 = 1500;
	TIM2->CCR3 = 1500;
	TIM2->CCR4 = 1500;
	
	while(1)
	{
	//
	}
}

