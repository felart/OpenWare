OPENWARE = $(CURDIR)

# Debug / Release
ifndef CONFIG
  CONFIG = Release
endif

.PHONY: clean

# To avoid problems on case insensitive filesystems, mark all targets named the same as a directory as phony
.PHONY: midiboot tesseract alchemist wizard owlpedal quadfm player prism magus effectsbox noctua daisypatch midibootdaisy biosignals witch lich

export OPENWARE CONFIG

all: alchemist wizard magus witch lich owlpedal midiboot noctua effectsbox biosignals daisypatch midibootdaisy # biosignals tesseract prism effectsbox player quadfm  ## build most targets

midiboot: ## build MidiBoot project
	@$(MAKE) -C MidiBoot all

tesseract: ## build Tesseract project
	@$(MAKE) -C Tesseract all

witch: ## build Witch project
	@$(MAKE) -C Witch all

lich: ## build Lich project
	@$(MAKE) -C Lich all

alchemist: ## build Alchemist project
	@$(MAKE) -C Alchemist all

wizard: ## build Wizard project
	@$(MAKE) -C Wizard all

owlpedal: ## build OWL Pedal project
	@$(MAKE) -C OwlPedal all

quadfm: ## build QuadFM project
	@$(MAKE) -C QuadFM all

player: ## build Player project
	@$(MAKE) -C PlayerF7 all

prism: ## build Prism project
	@$(MAKE) -C Prism all

magus: ## build Magus project
	@$(MAKE) -C Magus all

effectsbox: ## build EffectsBox project
	@$(MAKE) -C EffectsBox all

noctua: ## build Noctua project
	@$(MAKE) -C Noctua all

biosignals: ## build BioSignals project
	@$(MAKE) -C BioSignals all

daisypatch: ## build DaisyPatch project
	@$(MAKE) -C DaisyPatch all

midibootdaisy: ## build MidiBootDaisy project
	@$(MAKE) -C MidiBootDaisy all

clean: ## remove generated files
	@$(MAKE) -C Tesseract clean
	@$(MAKE) -C Witch clean
	@$(MAKE) -C Lich clean
	@$(MAKE) -C Alchemist clean
	@$(MAKE) -C Wizard clean
	@$(MAKE) -C OwlPedal clean
	@$(MAKE) -C PlayerF7 clean
	@$(MAKE) -C PrismF7 clean
	@$(MAKE) -C Prism clean
	@$(MAKE) -C Magus clean
	@$(MAKE) -C QuadFM clean
	@$(MAKE) -C EffectsBox clean
	@$(MAKE) -C Noctua clean
	@$(MAKE) -C BioSignals clean
	@$(MAKE) -C DaisyPatch clean

docs: ## generate HTML documentation
	@doxygen Doxyfile

help: ## show this help
	@echo 'Usage: make [target] ...'
	@echo 'Targets:'
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e  's/^\(.*\): .*##\(.*\)/\1:#\2/' | column -t -c 2 -s '#'
