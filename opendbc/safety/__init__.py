# constants from panda/python/__init__.py
DLC_TO_LEN = [0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64]
LEN_TO_DLC = {length: dlc for (dlc, length) in enumerate(DLC_TO_LEN)}


class Safety:
  # matches opendbc.structs.CarParams.SafetyModel
  # TODO: just use SafetyModel in panda repo
  SAFETY_SILENT = 0
  SAFETY_HONDA_NIDEC = 1
  SAFETY_TOYOTA = 2
  SAFETY_ELM327 = 3
  SAFETY_GM = 4
  SAFETY_HONDA_BOSCH_GIRAFFE = 5
  SAFETY_FORD = 6
  SAFETY_HYUNDAI = 8
  SAFETY_CHRYSLER = 9
  SAFETY_TESLA = 10
  SAFETY_SUBARU = 11
  SAFETY_MAZDA = 13
  SAFETY_NISSAN = 14
  SAFETY_VOLKSWAGEN_MQB = 15
  SAFETY_ALLOUTPUT = 17
  SAFETY_GM_ASCM = 18
  SAFETY_NOOUTPUT = 19
  SAFETY_HONDA_BOSCH = 20
  SAFETY_VOLKSWAGEN_PQ = 21
  SAFETY_SUBARU_PREGLOBAL = 22
  SAFETY_HYUNDAI_LEGACY = 23
  SAFETY_HYUNDAI_COMMUNITY = 24
  SAFETY_STELLANTIS = 25
  SAFETY_FAW = 26
  SAFETY_BODY = 27
  SAFETY_HYUNDAI_CANFD = 28


class ALTERNATIVE_EXPERIENCE:
  DEFAULT = 0
  DISABLE_DISENGAGE_ON_GAS = 1
  DISABLE_STOCK_AEB = 2
  RAISE_LONGITUDINAL_LIMITS_TO_ISO_MAX = 8
  ALLOW_AEB = 16
